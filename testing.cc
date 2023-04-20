#include <stdint.h>
#include <stddef.h>
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  if (size > 0 && data[0] == 'H')
    if (size > 1 && data[1] == 'I')
       if (size > 2 && data[2] == '!')
       __builtin_trap();
  return 0;
}

// Build test_fuzzer.cc with asan and link against libFuzzer.
// clang++ -fsanitize=address,fuzzer testing.cc
// Run the fuzzer with no corpus.
// ./a.out INPUT_CORPUS
