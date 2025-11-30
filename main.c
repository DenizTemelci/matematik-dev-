#include <stdio.h>
#include <math.h>

// Genel test noktasi (soru 2, 4, 5, 7, 10 harici fonksiyonlarda x=4 kullanýlýr)
#define TEST_X 4.0

// ----------------------------------------------------
// I. TUREV COZUM FONKSIYONLARI (Analitik Formuller)
// ----------------------------------------------------

// Soru 1: f(x)=x^(2/3) - x^(-1/2) -> f'(x) = (2/3)x^(-1/3) + (1/2)x^(-3/2)
double cozum_soru1(double x) {
    return (2.0 / 3.0) * pow(x, -1.0 / 3.0) + (1.0 / 2.0) * pow(x, -3.0 / 2.0);
}

// Soru 2: Parametrik (t=2) -> dy/dx = (3t^2 - 1) / (2t). t=2 icin 11/4.
double cozum_soru2() {
    double t = 2.0;
    double dy_dt = 3.0 * pow(t, 2.0) - 1.0;
    double dx_dt = 2.0 * t;
    return dy_dt / dx_dt;
}

// Soru 3: Logaritmik Turev: f(x)=x^cos(x)
// f'(x) = x^cos(x) * [ (cos(x)/x) - sin(x)*ln(x) ]
double cozum_soru3(double x) {
    double f_x = pow(x, cos(x));
    double term_in_bracket = (cos(x) / x) - (sin(x) * log(x)); // log() = ln
    return f_x * term_in_bracket;
}

// Soru 4: Teget Apsisleri Carpimi. 3x^2 - 4x - 4 = 0 -> Kokler Carpimi c/a = -4/3.
double cozum_soru4() {
    return -4.0 / 3.0;
}

// Orijinal Soru 5 fonksiyonu: f(x) = 2x^3 - 3x^2 - 12x + 5
double f_q5_orijinal(double x) {
    return 2.0 * pow(x, 3.0) - 3.0 * pow(x, 2.0) - 12.0 * x + 5.0;
}

// Soru 5: Mutlak Maksimum Hesabi: [-2, 3] araligi ve kritik noktalar (-1, 2) test edilir.
double cozum_soru5() {
    // Test noktalarý: -2, -1, 2, 3
    double x_vals[] = {-2.0, -1.0, 2.0, 3.0};
    double max_val = f_q5_orijinal(x_vals[0]);
    int i;
    for (i = 1; i < 4; i++) {
        double current_val = f_q5_orijinal(x_vals[i]);
        if (current_val > max_val) {
            max_val = current_val;
        }
    }
    return max_val; // Maksimum 12.
}

// Soru 6: Bolum Kurali: f'(x) = (x^2 - 4x - 1) / (x - 2)^2
double cozum_soru6(double x) {
    double numerator = pow(x, 2.0) - 4.0 * x - 1.0;
    double denominator = pow(x - 2.0, 2.0);
    return numerator / denominator;
}

// Soru 7: Parametrik (t=2) -> dy/dx = (3t^2 - 3) / (2t). t=2 icin 9/4.
double cozum_soru7() {
    double t = 2.0;
    double dy_dt = 3.0 * pow(t, 2.0) - 3.0;
    double dx_dt = 2.0 * t;
    return dy_dt / dx_dt;
}

// Soru 8: Logaritmik Turev: f(x)=x^sin(x)
// f'(x) = x^sin(x) * [ (sin(x)/x) + cos(x)*ln(x) ]
double cozum_soru8(double x) {
    double f_x = pow(x, sin(x));
    double term_in_bracket = (sin(x) / x) + (cos(x) * log(x));
    return f_x * term_in_bracket;
}

// Soru 9: 4. Dereceden Turev: y'''' = 720x - 192
double cozum_soru9(double x) {
    return 720.0 * x - 192.0;
}

// Soru 10: Turev x=0'da: f'(0) = 0
double cozum_soru10() {
    // f'(x) = x*e^x / (x+1)^2. x=0 koyuldugunda sonuc 0'dir.
    return 0.0;
}

// ----------------------------------------------------
// II. KONTROL VE MENU FONKSIYONLARI
// ----------------------------------------------------

void menu_goster() {
    printf("\n--- MATEMATIK-1 ODEVI COZUM MENUSU ---\n");
    printf("1. Soru: f(x)=x^(2/3) - 1/sqrt(x) turevi\n");
    printf("2. Soru: Parametrik dy/dx (t=2) x(t)=t^2+1, y(t)=t^3-t\n");
    printf("3. Soru: f(x)=x^cos(x) turevi\n");
    printf("4. Soru: Teget Apsisleri Carpimi\n");
    printf("5. Soru: Mutlak Maksimum ([-2, 3])\n");
    printf("6. Soru: f(x)=(x^2+1)/(x-2) turevi\n");
    printf("7. Soru: Parametrik dy/dx (t=2) x(t)=t^2, y(t)=t^3-3t\n");
    printf("8. Soru: f(x)=x^sin(x) turevi\n");
    printf("9. Soru: 4. Dereceden Turev\n");
    printf("10. Soru: f(x)=e^x/(x+1) x=0'da turev\n");
    printf("0. Cikis\n");
    printf("-----------------------------------------\n");
    printf("Lutfen cozmek istediginiz soru numarasini giriniz: ");
}

void secimi_islet(int secim) {
    double sonuc;
    printf("\n*** SORU %d ANALITIK COZUM SONUCU ***\n", secim);

    switch (secim) {
        case 1:
            sonuc = cozum_soru1(TEST_X);
            printf("Formul: (2/3)x^(-1/3) + (1/2)x^(-3/2)\n");
            printf("Test (x=%.1f) sonucu: %.6f\n", TEST_X, sonuc);
            break;
        case 2:
            sonuc = cozum_soru2();
            printf("Formul: (3t^2 - 1) / (2t)\n");
            printf("t=2 noktasindaki turev: %.6f\n", sonuc);
            break;
        case 3:
            sonuc = cozum_soru3(TEST_X);
            printf("Formul: x^cos(x) * [ (cos(x)/x) - sin(x)*ln(x) ]\n");
            printf("Test (x=%.1f) sonucu: %.6f\n", TEST_X, sonuc);
            break;
        case 4:
            sonuc = cozum_soru4();
            printf("Islem: 3x^2 - 4x - 4 = 0 kokler carpimi (c/a)\n");
            printf("Apsisler carpimi: %.6f\n", sonuc);
            break;
        case 5:
            sonuc = cozum_soru5();
            printf("Test edilen degerler: f(-2)=1, f(-1)=12, f(2)=-15, f(3)=-4\n");
            printf("Mutlak Maksimum: %.6f\n", sonuc);
            break;
        case 6:
            sonuc = cozum_soru6(TEST_X);
            printf("Formul: (x^2 - 4x - 1) / (x - 2)^2\n");
            printf("Test (x=%.1f) sonucu: %.6f\n", TEST_X, sonuc);
            break;
        case 7:
            sonuc = cozum_soru7();
            printf("Formul: (3t^2 - 3) / (2t)\n");
            printf("t=2 noktasindaki turev: %.6f\n", sonuc);
            break;
        case 8:
            sonuc = cozum_soru8(TEST_X);
            printf("Formul: x^sin(x) * [ (sin(x)/x) + cos(x)*ln(x) ]\n");
            printf("Test (x=%.1f) sonucu: %.6f\n", TEST_X, sonuc);
            break;
        case 9:
            sonuc = cozum_soru9(TEST_X);
            printf("Formul: 720x - 192\n");
            printf("Test (x=%.1f) sonucu: %.6f\n", TEST_X, sonuc);
            break;
        case 10:
            sonuc = cozum_soru10();
            printf("Formul: x*e^x / (x+1)^2\n");
            printf("x=0 noktasindaki turev: %.6f\n", sonuc);
            break;
        default:
            printf("Gecersiz secim.\n");
    }
    printf("-----------------------------------------\n");
}

int main() {
    int secim;

    do {
        menu_goster();
        // Kullanicidan secimi al ve hatayi kontrol et
        if (scanf("%d", &secim) != 1) {
            // Hata varsa giris tamponunu temizle
            while (getchar() != '\n');
            secim = -1;
        }

        if (secim >= 1 && secim <= 10) {
            secimi_islet(secim);
        } else if (secim != 0) {
            printf("\nHata: Lutfen 0 ile 10 arasinda gecerli bir sayi giriniz.\n");
        }

    } while (secim != 0);

    printf("\nProgram sonlandirildi. Iyi calismalar!\n");
    return 0;
}
