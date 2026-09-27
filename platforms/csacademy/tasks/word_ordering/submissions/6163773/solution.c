#include <stdio.h>
#include <stdlib.h> // qsort, malloc, free için
#include <string.h> // strlen için
#include <ctype.h>  // toupper için

/*
 * Global Sıralama Haritası (Rank Map)
 * Her ASCII karakterin özel sıralamadaki değerini tutar.
 */
int char_rank[256];

/**
 * @brief qsort için özel karşılaştırma fonksiyonu.
 * * Stringleri, global char_rank haritasına göre özel bir leksikografik
 * sırayla karşılaştırır.
 * * Kurallar:
 * 1. Harflerin sırası char_rank tarafından belirlenir.
 * 2. küçük harf < BÜYÜK HARF
 * 3. Kısa string, uzun stringin ön eki ise kısa olan önce gelir (örn: "word" < "wordpress")
 * * @param a Sıralanacak dizideki bir elemanın (char*) işaretçisi (yani const void* -> const char**).
 * @param b Sıralanacak dizideki diğer elemanın (char*) işaretçisi (yani const void* -> const char**).
 * @return 
 * < 0 (negatif) : a, b'den önce gelmeli
 * = 0 (sıfır)   : a ve b sıralama açısından eşit
 * > 0 (pozitif)  : a, b'den sonra gelmeli
 */
int custom_compare(const void *a, const void *b) {
    
    // qsort, elemanların adreslerini (pointerlarını) gönderir.
    // Dizimiz (char *strings[]), yani elemanlarımız (char *) tipindedir.
    // Bu yüzden 'a' ve 'b' (const char **) tipindedir.
    // * (dereference) operatörü ile asıl stringleri (const char *) elde ederiz.
    const char *str1 = *(const char **)a;
    const char *str2 = *(const char **)b;

    // İki string de bitene (null terminatör '\0' gelene) kadar döngüye gir
    while (*str1 && *str2) {
        // Karakterlerin rank'larını (değerlerini) haritadan al
        // (unsigned char) kullanarak negatif indisleri engelliyoruz
        int rank1 = char_rank[(unsigned char)*str1];
        int rank2 = char_rank[(unsigned char)*str2];

        // Eğer rank'lar farklıysa, sıralama belli olmuştur
        if (rank1 != rank2) {
            return rank1 - rank2; // Küçük rank'a sahip olan önce gelir
        }

        // Karakterler aynı rank'a sahip, sonraki karaktere geç
        str1++;
        str2++;
    }

    // Döngü bittiğinde, en az bir string'in sonuna gelinmiştir.
    // Durum 1: İkisi de bitti (str1 == "abc", str2 == "abc")
    if (*str1 == *str2) { // İkisi de '\0'
        return 0; // Eşitler
    }
    // Durum 2: str1 bitti, str2 bitmedi (str1 == "ana", str2 == "anagram")
    // str1 (kısa olan) önce gelmeli.
    else if (*str1 == '\0') {
        return -1; // str1 ön ek, önce gelir
    }
    // Durum 3: str2 bitti, str1 bitmedi (str1 == "anagram", str2 == "ana")
    // str2 (kısa olan) önce gelmeli.
    else { // *str2 == '\0'
        return 1; // str2 ön ek, sonra gelir
    }
}

int main() {
    // 1. Özel alfabeyi oku
    char custom_alphabet[27]; // 26 harf + '\0'
    scanf("%s", custom_alphabet);

    // 2. Sıralama haritasını (char_rank) oluştur
    for (int i = 0; i < 26; i++) {
        char lower = custom_alphabet[i];
        char upper = toupper(lower); // veya (lower - 'a' + 'A')

        // Kural: küçük harfler < BÜYÜK HARFLER
        // Küçük harflere 0-25 arası rank ata
        char_rank[(unsigned char)lower] = i;
        // Büyük harflere 26-51 arası rank ata
        char_rank[(unsigned char)upper] = i + 26;
    }

    // 3. String sayısı N'i oku
    int n;
    scanf("%d", &n);

    // 4. Bellek ayırma (Verimli Yöntem)
    // Stringlerin toplam uzunluğu <= 100000
    // N (string sayısı) <= 100000 (her biri için 1 null terminatör '\0')
    // Toplam karakter ihtiyacı <= 200000. Güvenlik için biraz fazla ayıralım.
    char *data_buffer = malloc(200005 * sizeof(char));
    if (data_buffer == NULL) {
        fprintf(stderr, "Bellek ayrılamadı (data_buffer)\n");
        return 1;
    }

    // N adet string işaretçisi (char*) için yer ayır
    char **strings = malloc(n * sizeof(char *));
    if (strings == NULL) {
        fprintf(stderr, "Bellek ayrılamadı (strings)\n");
        free(data_buffer);
        return 1;
    }

    // 5. Stringleri okuma
    char *current_ptr = data_buffer; // Büyük tamponun başını göster
    for (int i = 0; i < n; i++) {
        // String'i doğrudan tamponun (buffer) uygun yerine oku
        scanf("%s", current_ptr);
        
        // İşaretçi dizisinin i. elemanına, okuduğumuz stringin adresini ata
        strings[i] = current_ptr;
        
        // İşaretçiyi (current_ptr) bir sonraki stringin başlayacağı yere ilerlet
        // (Okunan stringin uzunluğu + 1 (null terminatör için))
        current_ptr += strlen(current_ptr) + 1;
    }

    // 6. Sıralama
    // qsort(dizi, eleman_sayısı, her_elemanın_boyutu, karşılaştırma_fonksiyonu)
    qsort(strings, n, sizeof(char *), custom_compare);

    // 7. Sonuçları yazdır
    for (int i = 0; i < n; i++) {
        printf("%s\n", strings[i]);
    }

    // 8. Ayrılan belleği serbest bırak
    free(data_buffer); // Tek büyük tamponu serbest bırak
    free(strings);     // İşaretçi dizisini serbest bırak

    return 0;
}