#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
float nhapSanLuongWh();
float doiWhSangKwh(float wh);
float tinhTienDien(float kwh, float donGia);

#ifndef UNIT_TEST
int main() {
  float wh = nhapSanLuongWh();
  float kwh = doiWhSangKwh(wh);
  float donGia = 3000.0; // Đơn giá ví dụ: 3000 VNĐ/kWh
  float tongTien = tinhTienDien(kwh, donGia);

  printf("\n--- HOA DON SAC XE ---");
  printf("\nSan luong: %.2f Wh", wh);
  printf("\nSan luong quy doi: %.2f kWh", kwh);
  printf("\nTong tien: %.2f VND\n", tongTien);

  return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CÁC HÀM DƯỚI ĐÂY ---
float nhapSanLuongWh() {
  float wh = 0.0f;
  int inputStatus;

  do {
    printf("Nhap san luong sac (Wh, phai lon hon 0): ");
    inputStatus = scanf("%f", &wh);

    if (inputStatus == EOF) {
      printf("\nKhong the doc du lieu dau vao.\n");
      return 0.0f;
    }

    if (inputStatus != 1) {
      int character;
      while ((character = getchar()) != '\n' && character != EOF) {
      }
      wh = 0.0f;
    } else if (!(wh > 0.0f)) {
      printf("Gia tri khong hop le. Vui long nhap lai.\n");
    }
  } while (!(wh > 0.0f));

  return wh;
}

float doiWhSangKwh(float wh) {
  return wh / 1000.0f;
}

float tinhTienDien(float kwh, float donGia) {
  return kwh * donGia;
}
