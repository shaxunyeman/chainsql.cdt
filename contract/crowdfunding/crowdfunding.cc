#include <chainsql/contract.h>
#include <chainsql/print.h>
#include <chainsql/storage.h>
#include <chainsql/context.h>
#include <chainsql/array.h>
#include <chainsql/system.h>
#include <stdint.h>


#define TARGET_FUNDS 10000000


CONTRACT crowdfunding : public chainsql::contract
{
public:
	using contract::contract;

	ACTION void init()
	{
		receiptor = chainsql::sender();
		chainsql::setState("receiptor", receiptor);
		chainsql::setState("current_funds", 0);
	}

	ACTION void donate()
	{
		int64_t value = chainsql::value();
		if (value <= 0)
			return;

		chainsql::account_id sender = chainsql::sender();

		if (funds.contains(sender))
		{
			funds[sender] = funds[sender] + value;
		}
		else
		{
			funds[sender] = value;
			funders.append(sender);
		}

		chainsql::getState("current_funds", current_funds);
		current_funds += value;
		chainsql::setState("current_funds", current_funds);
	}

	ACTION void complete()
	{
		chainsql::account_id sender = chainsql::sender();

		chainsql::getState("receiptor", receiptor);

		chainsql::check(sender == receiptor, "msg sender must be receiptor");

		chainsql::getState("current_funds", current_funds);
		chainsql::check(current_funds >= TARGET_FUNDS, "insufficient amount of crowdfunding");

		chainsql::self_destruct(receiptor);
	}

	ACTION void refund()
	{
		chainsql::account_id sender = chainsql::sender();

		chainsql::getState("receiptor", receiptor);

		chainsql::check(sender == receiptor, "msg sender must be receiptor");

		for (int i = 0; i < funders.size(); i++)
		{
			chainsql::account_id funder = funders[i];
			uint64_t amount = funds[funder];

			chainsql::check(amount > 0, "internal error");

			chainsql::pay(funder, amount);

			funds.erase(funder);
		}

		for (int i = funders.size() - 1; i >= 0; i--)
		{
			funders.remove(i);
		}
	}

	ACTION int64_t getfunds() const
	{
		chainsql::getState("current_funds", current_funds);
		return current_funds;
	}

private:
	chainsql::account_id receiptor;
	int64_t current_funds;

	chainsql::kv::map<chainsql::name("funder2value"), chainsql::account_id, int64_t> funds;
	chainsql::kv::array<chainsql::name("funders"), chainsql::account_id> funders;
};


