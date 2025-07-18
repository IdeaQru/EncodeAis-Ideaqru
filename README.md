# 🌊 EncodeAis-Ideaqru: AIS Messages Encoding Library for Arduino

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://github.com/IdeaQru/EncodeAis-Ideaqru/blob/main/LICENSE)
[![GitHub Issues](https://img.shields.io/github/issues/IdeaQru/EncodeAis-Ideaqru)](https://github.com/IdeaQru/EncodeAis-Ideaqru/issues)
[![Last Updated](https://img.shields.io/badge/Last%20Updated-June%202025-green)](https://github.com/IdeaQru/EncodeAis-Ideaqru/commits/main)

**EncodeAis-Ideaqru** adalah library Arduino yang inovatif dan modular untuk mengencode pesan AIS (Automatic Identification System) dalam format NMEA 0183. Dirancang untuk aplikasi maritim, library ini memungkinkan Anda menghasilkan pesan AIS dengan presisi bit-level untuk berbagai tipe pesan, ideal untuk proyek pelacakan kapal, aids-to-navigation, dan komunikasi keselamatan.

![AIS Encoding Flow](https://via.placeholder.com/800x400?text=AIS+Encoding+Flow+Diagram)  
*Diagram alur encoding pesan AIS (akan diperbarui dengan gambar sebenarnya setelah diunggah)*

## 📋 Daftar Isi
- [Tentang Proyek](#tentang-proyek)
- [Fitur Utama](#fitur-utama)
- [Tipe Pesan yang Didukung](#tipe-pesan-yang-didukung)
- [Instalasi](#instalasi)
- [Cara Penggunaan](#cara-penggunaan)
- [Contoh](#contoh)
- [Kontribusi](#kontribusi)
- [Lisensi](#lisensi)
- [Kredit](#kredit)
- [Demo Video](#demo-video)

## 🌟 Tentang Proyek
**EncodeAis-Ideaqru** dikembangkan untuk mempermudah pengembang Arduino dalam menciptakan pesan AIS yang sesuai standar untuk komunikasi maritim. Baik Anda sedang membangun sistem pelacakan kapal, aids-to-navigation, atau pesan keselamatan, library ini menyediakan solusi encoding yang akurat dan efisien. Proyek ini adalah hasil kerja tim IdeaQru, yang bertujuan untuk mendukung teknologi IoT maritim dengan pendekatan open-source.

## ✨ Fitur Utama
- **Dukungan Multi-Tipe Pesan**: Mengencode berbagai tipe pesan AIS dengan struktur data yang jelas dan mudah digunakan.
- **Presisi Bit-Level**: Memastikan payload AIS sesuai dengan spesifikasi ITU-R M.1371 untuk komunikasi yang andal.
- **Desain Modular**: Struktur kode yang fleksibel, memungkinkan penambahan tipe pesan baru atau modifikasi dengan mudah.
- **Kompatibilitas Arduino**: Dioptimalkan untuk platform Arduino, cocok untuk proyek embedded dengan sumber daya terbatas.
- **Output NMEA 0183**: Menghasilkan pesan dalam format standar yang siap digunakan dengan perangkat AIS atau decoder.

## 📡 Tipe Pesan yang Didukung
| Tipe Pesan | Deskripsi                          | Status         |
|------------|------------------------------------|----------------|
| 1, 2, 3    | Position Report (Class A)         | ✅ Didukung    |
| 8          | Binary Broadcast Message          | ✅ Didukung    |
| 14         | Safety Related Broadcast Message  | ✅ Didukung    |
| 18         | Position Report (Class B)         | ✅ Didukung    |
| 21         | Aids-to-Navigation Report         | ✅ Didukung    |
| 24A        | Static Data Report (Part A)       | ✅ Didukung    |
| 24B        | Static Data Report (Part B)       | ✅ Didukung    |

## 🛠 Instalasi
Untuk mulai menggunakan **EncodeAis-Ideaqru**, ikuti langkah-langkah berikut:

1. **Unduh Library**:
   - Unduh library dari repository ini dengan mengklik tombol "Code" > "Download ZIP".
   - Ekstrak folder `EncodeAis-Ideaqru` ke direktori library Arduino Anda (biasanya di `Documents/Arduino/libraries/`).

2. **Clone Repository (Opsional)**:
   Jika Anda menggunakan Git, Anda dapat mengkloning repository langsung:
