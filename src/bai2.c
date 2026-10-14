#include <stdio.h>

// --- INTERFACE BẮT BUỘC - KHÔNG ĐỔI CHỮ KÝ HÀM ---
int thanhToanHoaDon(float *soDuVi, float tongTien, float tyLeHoan, float *tienHoan);

#ifndef UNIT_TEST
int main() {
    float soDu = 500000.0;
    float hoaDon, tyLe;
    float tienDuocHoan = 0.0;

    printf("So du vi hien tai: %.2f VND\n", soDu);
    printf("Nhap so tien hoa don: ");
    scanf("%f", &hoaDon);
    printf("Nhap ty le cashback (%%): ");
    scanf("%f", &tyLe);

    int trangThai = thanhToanHoaDon(&soDu, hoaDon, tyLe, &tienDuocHoan);

    if (trangThai == 1) {
        printf("\n>> Giao dich THANH CONG!");
        printf("\nTien cashback nhan ve: %.2f VND", tienDuocHoan);
        printf("\nSo du vi sau cung: %.2f VND\n", soDu);
    } else {
        printf("\n>> Giao dich THAT BAI (So du khong du)!");
        printf("\nSo du giu nguyen: %.2f VND\n", soDu);
    }

    return 0;
}
#endif

// --- SINH VIÊN VIẾT CODE CỦA HÀM DƯỚI ĐÂY ---
int thanhToanHoaDon(float *soDuVi, float tongTien, float tyLeHoan, float *tienHoan) {
    if (soDuVi == NULL || tienHoan == NULL) {
        return 0;
    }

    *tienHoan = 0.0f;

    if (*soDuVi < tongTien) {
        return 0;
    }

    *tienHoan = tongTien * tyLeHoan / 100.0f;
    *soDuVi = *soDuVi - tongTien + *tienHoan;

    return 1;
}
