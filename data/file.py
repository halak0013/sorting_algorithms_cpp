# Dosyadaki karakterleri okuyarak sıralı ve tersine sıralı olarak yeni bir dosyaya yazma

# Dosya adı
dosya_adi = '32K_string_1'

for dosya_adi in ["32K_string_1","64K_string_1","128K_string_1","256K_string_1"]:
    try:
        # Dosyayı oku
        with open("random/"+dosya_adi, 'r') as dosya:
            icerik = dosya.read().strip()  # Dosya içeriğini oku ve boşlukları temizle

        # Karakterleri sırala
        sirali_karakterler = sorted(icerik)

        # Sıralı karakterleri tersine çevir
        tersine_sirali_karakterler = sirali_karakterler[::-1]

        # Yeni dosyaya yaz
        with open("sorted/"+dosya_adi, 'w') as yeni_dosya:
            yeni_dosya.write(''.join(sirali_karakterler))  # Sıralı karakterleri dosyaya yaz

        with open('reversed/'+dosya_adi,'w') as yeni_dosya:
            yeni_dosya.write('\n')  # Yeni satır ekle
            yeni_dosya.write(''.join(tersine_sirali_karakterler))  # Tersine sıralı karakterleri dosyaya yaz

        print("Karakterler sıralı ve tersine sıralı olarak 'sirali.txt' dosyasına kaydedildi.")

    except FileNotFoundError:
        print(f"'{dosya_adi}' adlı dosya bulunamadı.")
    except Exception as ex:
        print("Bir hata oluştu:", ex)
