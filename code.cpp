#include <iostream>
#include <string>
using namespace std;

struct KhachHang {
    int maKH;
    string tenKH;
    string soDienThoai;
    long long tongTien;
};

void nhap(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nKhach hang thu " << i + 1 << endl;

        cout << "Ma khach hang: ";
        cin >> a[i].maKH;
        cin.ignore();

        cout << "Ten khach hang: ";
        getline(cin, a[i].tenKH);

        cout << "So dien thoai: ";
        getline(cin, a[i].soDienThoai);

        cout << "Tong tien thanh toan: ";
        cin >> a[i].tongTien;
    }
}

void xuat(KhachHang a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nMa KH: " << a[i].maKH;
        cout << " | Ten: " << a[i].tenKH;
        cout << " | SDT: " << a[i].soDienThoai;
        cout << " | Tong tien: " << a[i].tongTien;
    }
}

void insertionSort(KhachHang a[], int n) {
    for (int i = 1; i < n; i++) {
        KhachHang x = a[i];
        int j = i - 1;

        while (j >= 0 && a[j].tongTien > x.tongTien) {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = x;
    }
}

void timKiem(KhachHang a[], int n, long long X) {
    int left = 0;
    int right = n - 1;
    int pos = -1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid].tongTien == X) {
            pos = mid;
            break;
        }

        if (a[mid].tongTien < X)
            left = mid + 1;
        else
            right = mid - 1;
    }

    if (pos == -1) {
        cout << "\nKhong tim thay khach hang co tong tien bang " << X << endl;
        return;
    }

    int i = pos;

    while (i >= 0 && a[i].tongTien == X)
        i--;

    i++;

    cout << "\nCac khach hang co tong tien bang " << X << ":";

    while (i < n && a[i].tongTien == X) {
        cout << "\nMa KH: " << a[i].maKH;
        cout << " | Ten: " << a[i].tenKH;
        cout << " | SDT: " << a[i].soDienThoai;
        cout << " | Tong tien: " << a[i].tongTien;
        i++;
    }
}

int main() {
    KhachHang a[100];
    int n;
    long long X;

    cout << "Nhap so luong khach hang: ";
    cin >> n;

    nhap(a, n);

    cout << "\n\nDANH SACH KHACH HANG VUA NHAP:";
    xuat(a, n);

    insertionSort(a, n);

    cout << "\n\nDANH SACH SAU KHI SAP XEP:";
    xuat(a, n);

    cout << "\n\nNhap X: ";
    cin >> X;

    timKiem(a, n, X);

    return 0;
}
