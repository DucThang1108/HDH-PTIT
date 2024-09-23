#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *disk;
  unsigned char fat[512];
  unsigned char memory[150];

  // mo o dia
  disk = fopen("D:", "rb");
  if (disk == NULL) {
  printf("Không the mo o dia D\n");
  return 1;
  }

  // Ðoc noi dung cua 150 o FAT dau tien
  fseek(disk, 0, SEEK_SET);
  fread(fat, sizeof(unsigned char), 512, disk);

  // In noi dung cua 150 o FAT dau tien
  printf("Noi dung cua 150 o FAT dau tien:\n");
  for (int i = 0; i < 150; i++) {
  printf("%02X ", fat[i]);
  }
  printf("\n");

  // In bang bit cua 150 khoi nho
  printf("bang bit cua 150 khoi nho:\n");
  for (int i = 0; i < 150; i++) {
  for (int j = 0; j < 8; j++) {
  printf("%d", (fat[i] >> j) & 1);
  }
  printf(" ");
  }
  printf("\n");

  // Ðóng o dia D
  fclose(disk);

  return 0;
}
