#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cau trúc du lieu cua mot file trong he thong file FAT16
typedef struct {
  char name[9]; // Tên file (8 ky tu + ky tu ket thúc chuoi)
  int size;     // Kích thuoc file (so khoi nho)
} File;

int main() {
  // Ðia chi bo nho cua thu muc goc
  void* root = /* Ðia chi bo nho cua thu muc goc */;

  // So luong file trong thu muc guc
  int numFiles = /* So luong file trong thu muc goc */;

  // Mang chua thông tin va các file trong thu muc goc
  File* files = (File*)malloc(numFiles * sizeof(File));

  // Ðoc thông tin va các file trong thu muc goc
  memcpy(files, root, numFiles * sizeof(File));

  // In tên và do dài cua các file trong thu muc goc
  for (int i = 0; i < numFiles; i++) {
  printf("File %d: %s, Size: %d blocks\n", i + 1, files[i].name, files[i].size);
  }

  // Tim mot file có tên cho truoc trong thu muc goc
  char targetName[9] = /* Tên file can tim */;
  int targetSize = 0;

  for (int i = 0; i < numFiles; i++) {
  if (strcmp(files[i].name, targetName) == 0) {
  targetSize = files[i].size;
  break;
  }
  }

  // In ket qua tim kiem
  if (targetSize > 0) {
  printf("File '%s' found. Size: %d blocks\n", targetName, targetSize);
  } else {
  printf("File '%s' not found\n", targetName);
  }

  // Giai phóng bo nho
  free(files);

  return 0;
}
