#include <stdint.h>
#include <stddef.h>

// returns 0 on success, -1 on error
int parse_coords_buff(char* in_coord_buf, int in_coords_buf_len, int** out_coords) {
  if (in_coord_buf_len < 0x1000) {
    return -1;
  }
  if (memcmp(in_coord_buf, in_coord_buf+8, 8) != 0) {
    // format failure
    return -1;
  }
  if (memcmp(in_coord_buf, "COORD", 500) != 0) {
    // format failure
    return -1;
  }

  if (in_coord_buf[0x150] + in_coord_buf[0x153] != in_coord_buf[0x180]) {
    return -1;
  } 

  size_t coords_count = (*(size_t*)in_coord_buf[10]) // get size from input buffer
  *out_coords = (int*)malloc(sizeof(size_t) * coords_count) 

  for (int i=0; i<out_coords_len; i++) {
    out_coords[i] = in_coord_buf[i] + in_coord_buf[i-1]
  }

  return 0;
}
