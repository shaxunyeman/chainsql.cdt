unsigned char math_wasm[] = {
  0x00, 0x61, 0x73, 0x6d, 0x01, 0x00, 0x00, 0x00, 0x01, 0x37, 0x0b, 0x60,
  0x00, 0x00, 0x60, 0x01, 0x7e, 0x00, 0x60, 0x01, 0x7f, 0x00, 0x60, 0x02,
  0x7f, 0x7f, 0x00, 0x60, 0x00, 0x01, 0x7f, 0x60, 0x03, 0x7f, 0x7f, 0x7f,
  0x01, 0x7f, 0x60, 0x02, 0x7f, 0x7f, 0x01, 0x7f, 0x60, 0x02, 0x7f, 0x7e,
  0x00, 0x60, 0x03, 0x7e, 0x7e, 0x7e, 0x00, 0x60, 0x01, 0x7f, 0x01, 0x7f,
  0x60, 0x02, 0x7e, 0x7e, 0x00, 0x02, 0xdb, 0x01, 0x0c, 0x03, 0x65, 0x6e,
  0x76, 0x06, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x69, 0x00, 0x01, 0x03, 0x65,
  0x6e, 0x76, 0x06, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x73, 0x00, 0x02, 0x03,
  0x65, 0x6e, 0x76, 0x08, 0x70, 0x72, 0x69, 0x6e, 0x74, 0x73, 0x5f, 0x6c,
  0x00, 0x03, 0x03, 0x65, 0x6e, 0x76, 0x10, 0x61, 0x63, 0x74, 0x69, 0x6f,
  0x6e, 0x5f, 0x64, 0x61, 0x74, 0x61, 0x5f, 0x73, 0x69, 0x7a, 0x65, 0x00,
  0x04, 0x03, 0x65, 0x6e, 0x76, 0x0f, 0x63, 0x68, 0x61, 0x69, 0x6e, 0x73,
  0x71, 0x6c, 0x5f, 0x61, 0x73, 0x73, 0x65, 0x72, 0x74, 0x00, 0x03, 0x03,
  0x65, 0x6e, 0x76, 0x06, 0x6d, 0x65, 0x6d, 0x73, 0x65, 0x74, 0x00, 0x05,
  0x03, 0x65, 0x6e, 0x76, 0x07, 0x6d, 0x65, 0x6d, 0x6d, 0x6f, 0x76, 0x65,
  0x00, 0x05, 0x03, 0x65, 0x6e, 0x76, 0x10, 0x72, 0x65, 0x61, 0x64, 0x5f,
  0x61, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x5f, 0x64, 0x61, 0x74, 0x61, 0x00,
  0x06, 0x03, 0x65, 0x6e, 0x76, 0x06, 0x6d, 0x65, 0x6d, 0x63, 0x70, 0x79,
  0x00, 0x05, 0x03, 0x65, 0x6e, 0x76, 0x17, 0x73, 0x65, 0x74, 0x5f, 0x61,
  0x63, 0x74, 0x69, 0x6f, 0x6e, 0x5f, 0x72, 0x65, 0x74, 0x75, 0x72, 0x6e,
  0x5f, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x00, 0x03, 0x03, 0x65, 0x6e, 0x76,
  0x05, 0x61, 0x62, 0x6f, 0x72, 0x74, 0x00, 0x00, 0x03, 0x65, 0x6e, 0x76,
  0x14, 0x63, 0x68, 0x61, 0x69, 0x6e, 0x73, 0x71, 0x6c, 0x5f, 0x61, 0x73,
  0x73, 0x65, 0x72, 0x74, 0x5f, 0x63, 0x6f, 0x64, 0x65, 0x00, 0x07, 0x03,
  0x15, 0x14, 0x00, 0x08, 0x09, 0x06, 0x02, 0x00, 0x04, 0x06, 0x05, 0x09,
  0x02, 0x02, 0x02, 0x02, 0x02, 0x05, 0x05, 0x0a, 0x03, 0x0a, 0x04, 0x05,
  0x01, 0x70, 0x01, 0x01, 0x01, 0x05, 0x03, 0x01, 0x00, 0x01, 0x06, 0x16,
  0x03, 0x7f, 0x01, 0x41, 0x80, 0xc0, 0x00, 0x0b, 0x7f, 0x00, 0x41, 0xa0,
  0xc1, 0x00, 0x0b, 0x7f, 0x00, 0x41, 0xa0, 0xc1, 0x00, 0x0b, 0x07, 0x09,
  0x01, 0x05, 0x61, 0x70, 0x70, 0x6c, 0x79, 0x00, 0x0d, 0x0a, 0xd8, 0x0f,
  0x14, 0x04, 0x00, 0x10, 0x11, 0x0b, 0x91, 0x01, 0x00, 0x10, 0x0c, 0x20,
  0x00, 0x20, 0x01, 0x51, 0x04, 0x40, 0x42, 0x80, 0x80, 0x80, 0x80, 0x80,
  0x80, 0x80, 0xa9, 0x32, 0x20, 0x02, 0x51, 0x04, 0x40, 0x20, 0x00, 0x20,
  0x01, 0x10, 0x1d, 0x05, 0x42, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xe4,
  0xd1, 0x96, 0x7f, 0x20, 0x02, 0x51, 0x04, 0x40, 0x20, 0x00, 0x20, 0x01,
  0x10, 0x1f, 0x05, 0x20, 0x00, 0x42, 0x80, 0x80, 0x80, 0x88, 0xad, 0xbc,
  0xba, 0xa6, 0xc3, 0x00, 0x52, 0x04, 0x40, 0x41, 0x00, 0x42, 0x80, 0x80,
  0x80, 0xd9, 0xd3, 0xb3, 0xed, 0x82, 0xef, 0x00, 0x10, 0x0b, 0x0b, 0x0b,
  0x0b, 0x05, 0x42, 0x80, 0x80, 0x80, 0x88, 0xad, 0xbc, 0xba, 0xa6, 0xc3,
  0x00, 0x20, 0x01, 0x51, 0x04, 0x40, 0x42, 0x80, 0x80, 0x80, 0x80, 0xae,
  0xfa, 0xde, 0xea, 0xa4, 0x7f, 0x20, 0x02, 0x51, 0x04, 0x40, 0x41, 0x00,
  0x42, 0x81, 0x80, 0x80, 0xd9, 0xd3, 0xb3, 0xed, 0x82, 0xef, 0x00, 0x10,
  0x0b, 0x0b, 0x0b, 0x0b, 0x41, 0x00, 0x10, 0x19, 0x0b, 0x72, 0x01, 0x03,
  0x7f, 0x02, 0x40, 0x20, 0x00, 0x0d, 0x00, 0x41, 0x00, 0x0f, 0x0b, 0x41,
  0x00, 0x41, 0x00, 0x28, 0x02, 0x8c, 0x40, 0x20, 0x00, 0x41, 0x10, 0x76,
  0x22, 0x01, 0x6a, 0x22, 0x02, 0x36, 0x02, 0x8c, 0x40, 0x41, 0x00, 0x41,
  0x00, 0x28, 0x02, 0x84, 0x40, 0x22, 0x03, 0x20, 0x00, 0x6a, 0x41, 0x0f,
  0x6a, 0x41, 0x70, 0x71, 0x22, 0x00, 0x36, 0x02, 0x84, 0x40, 0x02, 0x40,
  0x20, 0x02, 0x41, 0x10, 0x74, 0x20, 0x00, 0x4b, 0x0d, 0x00, 0x41, 0x00,
  0x20, 0x02, 0x41, 0x01, 0x6a, 0x36, 0x02, 0x8c, 0x40, 0x20, 0x01, 0x41,
  0x01, 0x6a, 0x21, 0x01, 0x0b, 0x02, 0x40, 0x20, 0x01, 0x40, 0x00, 0x41,
  0x7f, 0x47, 0x0d, 0x00, 0x41, 0x00, 0x41, 0x90, 0xc0, 0x00, 0x10, 0x04,
  0x0b, 0x20, 0x03, 0x0b, 0x8a, 0x01, 0x01, 0x03, 0x7f, 0x02, 0x40, 0x20,
  0x01, 0x20, 0x00, 0x6c, 0x22, 0x01, 0x0d, 0x00, 0x41, 0x00, 0x0f, 0x0b,
  0x41, 0x00, 0x41, 0x00, 0x28, 0x02, 0x8c, 0x40, 0x20, 0x01, 0x41, 0x10,
  0x76, 0x22, 0x02, 0x6a, 0x22, 0x03, 0x36, 0x02, 0x8c, 0x40, 0x41, 0x00,
  0x41, 0x00, 0x28, 0x02, 0x84, 0x40, 0x22, 0x00, 0x20, 0x01, 0x6a, 0x41,
  0x0f, 0x6a, 0x41, 0x70, 0x71, 0x22, 0x04, 0x36, 0x02, 0x84, 0x40, 0x02,
  0x40, 0x20, 0x03, 0x41, 0x10, 0x74, 0x20, 0x04, 0x4b, 0x0d, 0x00, 0x41,
  0x00, 0x20, 0x03, 0x41, 0x01, 0x6a, 0x36, 0x02, 0x8c, 0x40, 0x20, 0x02,
  0x41, 0x01, 0x6a, 0x21, 0x02, 0x0b, 0x02, 0x40, 0x20, 0x02, 0x40, 0x00,
  0x41, 0x7f, 0x47, 0x0d, 0x00, 0x41, 0x00, 0x41, 0x90, 0xc0, 0x00, 0x10,
  0x04, 0x0b, 0x02, 0x40, 0x20, 0x00, 0x0d, 0x00, 0x41, 0x00, 0x0f, 0x0b,
  0x20, 0x00, 0x41, 0x00, 0x20, 0x01, 0x10, 0x05, 0x1a, 0x20, 0x00, 0x0b,
  0x02, 0x00, 0x0b, 0x36, 0x01, 0x01, 0x7f, 0x23, 0x00, 0x41, 0x10, 0x6b,
  0x22, 0x00, 0x41, 0x00, 0x36, 0x02, 0x0c, 0x41, 0x00, 0x20, 0x00, 0x28,
  0x02, 0x0c, 0x28, 0x02, 0x00, 0x41, 0x0f, 0x6a, 0x41, 0x70, 0x71, 0x22,
  0x00, 0x36, 0x02, 0x80, 0x40, 0x41, 0x00, 0x20, 0x00, 0x36, 0x02, 0x84,
  0x40, 0x41, 0x00, 0x3f, 0x00, 0x36, 0x02, 0x8c, 0x40, 0x0b, 0x06, 0x00,
  0x41, 0xb4, 0xc0, 0x00, 0x0b, 0x88, 0x02, 0x01, 0x06, 0x7f, 0x02, 0x40,
  0x20, 0x00, 0x20, 0x00, 0x41, 0x7f, 0x6a, 0x71, 0x45, 0x0d, 0x00, 0x10,
  0x12, 0x41, 0x16, 0x36, 0x02, 0x00, 0x41, 0x00, 0x0f, 0x0b, 0x02, 0x40,
  0x20, 0x00, 0x41, 0x7f, 0x73, 0x20, 0x01, 0x4f, 0x0d, 0x00, 0x10, 0x12,
  0x41, 0x0c, 0x36, 0x02, 0x00, 0x41, 0x00, 0x0f, 0x0b, 0x02, 0x40, 0x20,
  0x00, 0x41, 0x10, 0x4b, 0x0d, 0x00, 0x20, 0x01, 0x10, 0x0e, 0x0f, 0x0b,
  0x02, 0x40, 0x20, 0x00, 0x41, 0x7f, 0x6a, 0x22, 0x02, 0x20, 0x01, 0x6a,
  0x10, 0x0e, 0x22, 0x01, 0x0d, 0x00, 0x41, 0x00, 0x0f, 0x0b, 0x02, 0x40,
  0x20, 0x01, 0x20, 0x02, 0x20, 0x01, 0x6a, 0x41, 0x00, 0x20, 0x00, 0x6b,
  0x71, 0x22, 0x00, 0x47, 0x0d, 0x00, 0x20, 0x01, 0x0f, 0x0b, 0x02, 0x40,
  0x20, 0x01, 0x41, 0x7c, 0x6a, 0x22, 0x03, 0x28, 0x02, 0x00, 0x22, 0x04,
  0x41, 0x07, 0x71, 0x22, 0x02, 0x0d, 0x00, 0x20, 0x00, 0x41, 0x78, 0x6a,
  0x20, 0x01, 0x41, 0x78, 0x6a, 0x28, 0x02, 0x00, 0x20, 0x00, 0x20, 0x01,
  0x6b, 0x22, 0x01, 0x6a, 0x36, 0x02, 0x00, 0x20, 0x00, 0x41, 0x7c, 0x6a,
  0x20, 0x03, 0x28, 0x02, 0x00, 0x20, 0x01, 0x6b, 0x36, 0x02, 0x00, 0x20,
  0x00, 0x0f, 0x0b, 0x20, 0x01, 0x20, 0x04, 0x41, 0x78, 0x71, 0x6a, 0x22,
  0x04, 0x41, 0x78, 0x6a, 0x22, 0x05, 0x28, 0x02, 0x00, 0x21, 0x06, 0x20,
  0x03, 0x20, 0x02, 0x20, 0x00, 0x20, 0x01, 0x6b, 0x22, 0x07, 0x72, 0x36,
  0x02, 0x00, 0x20, 0x00, 0x41, 0x7c, 0x6a, 0x20, 0x04, 0x20, 0x00, 0x6b,
  0x22, 0x03, 0x20, 0x02, 0x72, 0x36, 0x02, 0x00, 0x20, 0x00, 0x41, 0x78,
  0x6a, 0x20, 0x06, 0x41, 0x07, 0x71, 0x22, 0x02, 0x20, 0x07, 0x72, 0x36,
  0x02, 0x00, 0x20, 0x05, 0x20, 0x02, 0x20, 0x03, 0x72, 0x36, 0x02, 0x00,
  0x20, 0x01, 0x10, 0x10, 0x20, 0x00, 0x0b, 0x32, 0x01, 0x01, 0x7f, 0x41,
  0x16, 0x21, 0x03, 0x02, 0x40, 0x20, 0x01, 0x41, 0x04, 0x49, 0x0d, 0x00,
  0x02, 0x40, 0x20, 0x01, 0x20, 0x02, 0x10, 0x13, 0x22, 0x01, 0x0d, 0x00,
  0x10, 0x12, 0x28, 0x02, 0x00, 0x0f, 0x0b, 0x20, 0x00, 0x20, 0x01, 0x36,
  0x02, 0x00, 0x41, 0x00, 0x21, 0x03, 0x0b, 0x20, 0x03, 0x0b, 0x33, 0x01,
  0x02, 0x7f, 0x20, 0x00, 0x41, 0x01, 0x20, 0x00, 0x1b, 0x21, 0x01, 0x02,
  0x40, 0x03, 0x40, 0x20, 0x01, 0x10, 0x0e, 0x22, 0x00, 0x0d, 0x01, 0x41,
  0x00, 0x21, 0x00, 0x41, 0x00, 0x28, 0x02, 0xbc, 0x40, 0x22, 0x02, 0x45,
  0x0d, 0x01, 0x20, 0x02, 0x11, 0x00, 0x00, 0x0c, 0x00, 0x0b, 0x0b, 0x20,
  0x00, 0x0b, 0x06, 0x00, 0x20, 0x00, 0x10, 0x10, 0x0b, 0x09, 0x00, 0x20,
  0x00, 0x41, 0x01, 0x36, 0x02, 0x00, 0x0b, 0x09, 0x00, 0x20, 0x00, 0x41,
  0x00, 0x36, 0x02, 0x00, 0x0b, 0x02, 0x00, 0x0b, 0x05, 0x00, 0x10, 0x0a,
  0x00, 0x0b, 0x81, 0x01, 0x01, 0x02, 0x7f, 0x20, 0x01, 0xac, 0x10, 0x00,
  0x20, 0x02, 0x20, 0x01, 0x6a, 0x21, 0x03, 0x41, 0xaa, 0xc0, 0x00, 0x21,
  0x01, 0x02, 0x40, 0x03, 0x40, 0x20, 0x01, 0x2d, 0x00, 0x00, 0x22, 0x04,
  0x45, 0x0d, 0x01, 0x02, 0x40, 0x20, 0x04, 0x41, 0x25, 0x47, 0x0d, 0x00,
  0x20, 0x02, 0xac, 0x10, 0x00, 0x20, 0x01, 0x41, 0x01, 0x6a, 0x21, 0x01,
  0x03, 0x40, 0x20, 0x01, 0x2d, 0x00, 0x00, 0x22, 0x04, 0x45, 0x0d, 0x03,
  0x02, 0x40, 0x20, 0x04, 0x41, 0x25, 0x47, 0x0d, 0x00, 0x20, 0x03, 0xac,
  0x10, 0x00, 0x20, 0x01, 0x41, 0x01, 0x6a, 0x10, 0x01, 0x0c, 0x04, 0x0b,
  0x20, 0x01, 0x41, 0x01, 0x10, 0x02, 0x20, 0x01, 0x41, 0x01, 0x6a, 0x21,
  0x01, 0x0c, 0x00, 0x0b, 0x0b, 0x20, 0x01, 0x41, 0x01, 0x10, 0x02, 0x20,
  0x01, 0x41, 0x01, 0x6a, 0x21, 0x01, 0x0c, 0x00, 0x0b, 0x0b, 0x20, 0x03,
  0x0b, 0x81, 0x01, 0x01, 0x02, 0x7f, 0x20, 0x01, 0xac, 0x10, 0x00, 0x20,
  0x02, 0x20, 0x01, 0x6c, 0x21, 0x03, 0x41, 0xc1, 0xc0, 0x00, 0x21, 0x01,
  0x02, 0x40, 0x03, 0x40, 0x20, 0x01, 0x2d, 0x00, 0x00, 0x22, 0x04, 0x45,
  0x0d, 0x01, 0x02, 0x40, 0x20, 0x04, 0x41, 0x25, 0x47, 0x0d, 0x00, 0x20,
  0x02, 0xac, 0x10, 0x00, 0x20, 0x01, 0x41, 0x01, 0x6a, 0x21, 0x01, 0x03,
  0x40, 0x20, 0x01, 0x2d, 0x00, 0x00, 0x22, 0x04, 0x45, 0x0d, 0x03, 0x02,
  0x40, 0x20, 0x04, 0x41, 0x25, 0x47, 0x0d, 0x00, 0x20, 0x03, 0xac, 0x10,
  0x00, 0x20, 0x01, 0x41, 0x01, 0x6a, 0x10, 0x01, 0x0c, 0x04, 0x0b, 0x20,
  0x01, 0x41, 0x01, 0x10, 0x02, 0x20, 0x01, 0x41, 0x01, 0x6a, 0x21, 0x01,
  0x0c, 0x00, 0x0b, 0x0b, 0x20, 0x01, 0x41, 0x01, 0x10, 0x02, 0x20, 0x01,
  0x41, 0x01, 0x6a, 0x21, 0x01, 0x0c, 0x00, 0x0b, 0x0b, 0x20, 0x03, 0x0b,
  0xa3, 0x02, 0x01, 0x04, 0x7f, 0x23, 0x00, 0x41, 0x20, 0x6b, 0x22, 0x02,
  0x21, 0x03, 0x20, 0x02, 0x24, 0x00, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40,
  0x10, 0x03, 0x22, 0x04, 0x0d, 0x00, 0x41, 0x00, 0x21, 0x02, 0x20, 0x03,
  0x41, 0x1c, 0x6a, 0x21, 0x05, 0x0c, 0x01, 0x0b, 0x02, 0x40, 0x02, 0x40,
  0x20, 0x04, 0x41, 0x80, 0x04, 0x49, 0x0d, 0x00, 0x20, 0x04, 0x10, 0x0e,
  0x21, 0x02, 0x0c, 0x01, 0x0b, 0x20, 0x02, 0x20, 0x04, 0x41, 0x0f, 0x6a,
  0x41, 0x70, 0x71, 0x6b, 0x22, 0x02, 0x24, 0x00, 0x0b, 0x20, 0x02, 0x20,
  0x04, 0x10, 0x07, 0x1a, 0x20, 0x03, 0x41, 0x1c, 0x6a, 0x21, 0x05, 0x20,
  0x04, 0x41, 0x03, 0x4b, 0x0d, 0x01, 0x0b, 0x41, 0x00, 0x41, 0xcb, 0xc0,
  0x00, 0x10, 0x04, 0x0b, 0x20, 0x05, 0x20, 0x02, 0x41, 0x04, 0x10, 0x08,
  0x1a, 0x20, 0x02, 0x41, 0x04, 0x6a, 0x21, 0x02, 0x02, 0x40, 0x20, 0x04,
  0x41, 0x7c, 0x71, 0x41, 0x04, 0x47, 0x0d, 0x00, 0x41, 0x00, 0x41, 0xcb,
  0xc0, 0x00, 0x10, 0x04, 0x0b, 0x20, 0x03, 0x41, 0x18, 0x6a, 0x20, 0x02,
  0x41, 0x04, 0x10, 0x08, 0x1a, 0x20, 0x03, 0x20, 0x03, 0x20, 0x03, 0x28,
  0x02, 0x1c, 0x20, 0x03, 0x28, 0x02, 0x18, 0x10, 0x1b, 0x36, 0x02, 0x14,
  0x20, 0x03, 0x41, 0x00, 0x36, 0x02, 0x10, 0x20, 0x03, 0x42, 0x00, 0x37,
  0x03, 0x08, 0x20, 0x03, 0x41, 0x08, 0x6a, 0x41, 0x04, 0x10, 0x1e, 0x02,
  0x40, 0x20, 0x03, 0x28, 0x02, 0x0c, 0x20, 0x03, 0x28, 0x02, 0x08, 0x22,
  0x04, 0x6b, 0x41, 0x03, 0x4a, 0x0d, 0x00, 0x41, 0x00, 0x41, 0xf5, 0xc0,
  0x00, 0x10, 0x04, 0x0b, 0x20, 0x04, 0x20, 0x03, 0x41, 0x14, 0x6a, 0x41,
  0x04, 0x10, 0x08, 0x1a, 0x20, 0x03, 0x28, 0x02, 0x08, 0x22, 0x04, 0x20,
  0x03, 0x28, 0x02, 0x0c, 0x20, 0x04, 0x6b, 0x10, 0x09, 0x02, 0x40, 0x20,
  0x03, 0x28, 0x02, 0x08, 0x22, 0x04, 0x45, 0x0d, 0x00, 0x20, 0x03, 0x20,
  0x04, 0x36, 0x02, 0x0c, 0x20, 0x04, 0x10, 0x16, 0x0b, 0x20, 0x03, 0x41,
  0x20, 0x6a, 0x24, 0x00, 0x0b, 0x98, 0x02, 0x01, 0x05, 0x7f, 0x02, 0x40,
  0x02, 0x40, 0x02, 0x40, 0x20, 0x00, 0x28, 0x02, 0x08, 0x22, 0x02, 0x20,
  0x00, 0x28, 0x02, 0x04, 0x22, 0x03, 0x6b, 0x20, 0x01, 0x49, 0x0d, 0x00,
  0x03, 0x40, 0x20, 0x03, 0x41, 0x00, 0x3a, 0x00, 0x00, 0x20, 0x00, 0x20,
  0x00, 0x28, 0x02, 0x04, 0x41, 0x01, 0x6a, 0x22, 0x03, 0x36, 0x02, 0x04,
  0x20, 0x01, 0x41, 0x7f, 0x6a, 0x22, 0x01, 0x0d, 0x00, 0x0c, 0x02, 0x0b,
  0x0b, 0x20, 0x03, 0x20, 0x00, 0x28, 0x02, 0x00, 0x22, 0x04, 0x6b, 0x22,
  0x05, 0x20, 0x01, 0x6a, 0x22, 0x06, 0x41, 0x7f, 0x4c, 0x0d, 0x01, 0x41,
  0xff, 0xff, 0xff, 0xff, 0x07, 0x21, 0x03, 0x02, 0x40, 0x02, 0x40, 0x20,
  0x02, 0x20, 0x04, 0x6b, 0x22, 0x02, 0x41, 0xfe, 0xff, 0xff, 0xff, 0x03,
  0x4b, 0x0d, 0x00, 0x20, 0x06, 0x20, 0x02, 0x41, 0x01, 0x74, 0x22, 0x03,
  0x20, 0x03, 0x20, 0x06, 0x49, 0x1b, 0x22, 0x03, 0x0d, 0x00, 0x41, 0x00,
  0x21, 0x03, 0x41, 0x00, 0x21, 0x02, 0x0c, 0x01, 0x0b, 0x20, 0x03, 0x10,
  0x15, 0x21, 0x02, 0x0b, 0x20, 0x02, 0x20, 0x03, 0x6a, 0x21, 0x06, 0x20,
  0x02, 0x20, 0x05, 0x6a, 0x22, 0x04, 0x21, 0x03, 0x03, 0x40, 0x20, 0x03,
  0x41, 0x00, 0x3a, 0x00, 0x00, 0x20, 0x03, 0x41, 0x01, 0x6a, 0x21, 0x03,
  0x20, 0x01, 0x41, 0x7f, 0x6a, 0x22, 0x01, 0x0d, 0x00, 0x0b, 0x20, 0x04,
  0x20, 0x00, 0x28, 0x02, 0x04, 0x20, 0x00, 0x28, 0x02, 0x00, 0x22, 0x01,
  0x6b, 0x22, 0x02, 0x6b, 0x21, 0x04, 0x02, 0x40, 0x20, 0x02, 0x41, 0x01,
  0x48, 0x0d, 0x00, 0x20, 0x04, 0x20, 0x01, 0x20, 0x02, 0x10, 0x08, 0x1a,
  0x20, 0x00, 0x28, 0x02, 0x00, 0x21, 0x01, 0x0b, 0x20, 0x00, 0x20, 0x06,
  0x36, 0x02, 0x08, 0x20, 0x00, 0x20, 0x03, 0x36, 0x02, 0x04, 0x20, 0x00,
  0x20, 0x04, 0x36, 0x02, 0x00, 0x20, 0x01, 0x45, 0x0d, 0x00, 0x20, 0x01,
  0x10, 0x16, 0x0b, 0x0f, 0x0b, 0x20, 0x00, 0x10, 0x1a, 0x00, 0x0b, 0xa3,
  0x02, 0x01, 0x04, 0x7f, 0x23, 0x00, 0x41, 0x20, 0x6b, 0x22, 0x02, 0x21,
  0x03, 0x20, 0x02, 0x24, 0x00, 0x02, 0x40, 0x02, 0x40, 0x02, 0x40, 0x10,
  0x03, 0x22, 0x04, 0x0d, 0x00, 0x41, 0x00, 0x21, 0x02, 0x20, 0x03, 0x41,
  0x1c, 0x6a, 0x21, 0x05, 0x0c, 0x01, 0x0b, 0x02, 0x40, 0x02, 0x40, 0x20,
  0x04, 0x41, 0x80, 0x04, 0x49, 0x0d, 0x00, 0x20, 0x04, 0x10, 0x0e, 0x21,
  0x02, 0x0c, 0x01, 0x0b, 0x20, 0x02, 0x20, 0x04, 0x41, 0x0f, 0x6a, 0x41,
  0x70, 0x71, 0x6b, 0x22, 0x02, 0x24, 0x00, 0x0b, 0x20, 0x02, 0x20, 0x04,
  0x10, 0x07, 0x1a, 0x20, 0x03, 0x41, 0x1c, 0x6a, 0x21, 0x05, 0x20, 0x04,
  0x41, 0x03, 0x4b, 0x0d, 0x01, 0x0b, 0x41, 0x00, 0x41, 0xcb, 0xc0, 0x00,
  0x10, 0x04, 0x0b, 0x20, 0x05, 0x20, 0x02, 0x41, 0x04, 0x10, 0x08, 0x1a,
  0x20, 0x02, 0x41, 0x04, 0x6a, 0x21, 0x02, 0x02, 0x40, 0x20, 0x04, 0x41,
  0x7c, 0x71, 0x41, 0x04, 0x47, 0x0d, 0x00, 0x41, 0x00, 0x41, 0xcb, 0xc0,
  0x00, 0x10, 0x04, 0x0b, 0x20, 0x03, 0x41, 0x18, 0x6a, 0x20, 0x02, 0x41,
  0x04, 0x10, 0x08, 0x1a, 0x20, 0x03, 0x20, 0x03, 0x20, 0x03, 0x28, 0x02,
  0x1c, 0x20, 0x03, 0x28, 0x02, 0x18, 0x10, 0x1c, 0x36, 0x02, 0x14, 0x20,
  0x03, 0x41, 0x00, 0x36, 0x02, 0x10, 0x20, 0x03, 0x42, 0x00, 0x37, 0x03,
  0x08, 0x20, 0x03, 0x41, 0x08, 0x6a, 0x41, 0x04, 0x10, 0x1e, 0x02, 0x40,
  0x20, 0x03, 0x28, 0x02, 0x0c, 0x20, 0x03, 0x28, 0x02, 0x08, 0x22, 0x04,
  0x6b, 0x41, 0x03, 0x4a, 0x0d, 0x00, 0x41, 0x00, 0x41, 0xf5, 0xc0, 0x00,
  0x10, 0x04, 0x0b, 0x20, 0x04, 0x20, 0x03, 0x41, 0x14, 0x6a, 0x41, 0x04,
  0x10, 0x08, 0x1a, 0x20, 0x03, 0x28, 0x02, 0x08, 0x22, 0x04, 0x20, 0x03,
  0x28, 0x02, 0x0c, 0x20, 0x04, 0x6b, 0x10, 0x09, 0x02, 0x40, 0x20, 0x03,
  0x28, 0x02, 0x08, 0x22, 0x04, 0x45, 0x0d, 0x00, 0x20, 0x03, 0x20, 0x04,
  0x36, 0x02, 0x0c, 0x20, 0x04, 0x10, 0x16, 0x0b, 0x20, 0x03, 0x41, 0x20,
  0x6a, 0x24, 0x00, 0x0b, 0x0b, 0xaa, 0x01, 0x05, 0x00, 0x41, 0x90, 0xc0,
  0x00, 0x0b, 0x24, 0x66, 0x61, 0x69, 0x6c, 0x65, 0x64, 0x20, 0x74, 0x6f,
  0x20, 0x61, 0x6c, 0x6c, 0x6f, 0x63, 0x61, 0x74, 0x65, 0x20, 0x70, 0x61,
  0x67, 0x65, 0x73, 0x00, 0x25, 0x20, 0x2b, 0x20, 0x25, 0x20, 0x3d, 0x20,
  0x25, 0x0a, 0x00, 0x00, 0x41, 0xc0, 0xc0, 0x00, 0x0b, 0x0b, 0x25, 0x20,
  0x2a, 0x20, 0x25, 0x20, 0x3d, 0x20, 0x25, 0x0a, 0x00, 0x00, 0x41, 0xcb,
  0xc0, 0x00, 0x0b, 0x2a, 0x64, 0x61, 0x74, 0x61, 0x73, 0x74, 0x72, 0x65,
  0x61, 0x6d, 0x20, 0x61, 0x74, 0x74, 0x65, 0x6d, 0x70, 0x74, 0x65, 0x64,
  0x20, 0x74, 0x6f, 0x20, 0x72, 0x65, 0x61, 0x64, 0x20, 0x70, 0x61, 0x73,
  0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x6e, 0x64, 0x00, 0x00, 0x41,
  0xf5, 0xc0, 0x00, 0x0b, 0x2b, 0x64, 0x61, 0x74, 0x61, 0x73, 0x74, 0x72,
  0x65, 0x61, 0x6d, 0x20, 0x61, 0x74, 0x74, 0x65, 0x6d, 0x70, 0x74, 0x65,
  0x64, 0x20, 0x74, 0x6f, 0x20, 0x77, 0x72, 0x69, 0x74, 0x65, 0x20, 0x70,
  0x61, 0x73, 0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x65, 0x6e, 0x64, 0x00,
  0x00, 0x41, 0x00, 0x0b, 0x04, 0xa0, 0x20, 0x00, 0x00
};
unsigned int math_wasm_len = 2541;
