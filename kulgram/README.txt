
Ok, sekarang kita akan mencoba praktek menggunakan angr, disini saya sudah membuat
contoh program2 yg akan kita gunakan di praktek ini

program yg pertama adalah, program yg sederhana yg meminta inputan berupa password,
seperti ini programnya

[Image: strcmp.png]

programnya sangat sederhana. disini tujuannya bukan mendapatkan password yg benar.
tapi, menggunakan angr sebagai symbolic execution untuk mencari apa seharusnya inputan
kita, agar eksekusi program berada pada suatu kondisi tertentu.

kondisi yg dinginkan adalah dimana program counter (PC) berada didalam blok if. skripnya
seperti ini.

[Image: solve_strcmp.png]

disini kita menggunakan "path" yg disediakan angr untuk mengontrol eksekusi program. dalam
sekali eksekusi, path dapat berjumlah lebih dari 1 yg masing2 mempunyai state tersendiri.

contohnya program diatas, terdapat 1 percabangan (blok if dan else), setelah melewati eksekusi tsb
path akan berjumlah 2, path pertama berada di blok if, dan yg kedua berada di dalam di blok else.
begitu juga dengan 2 percabangan (nested if), path akan berjumlah 4, layaknya fork() di linux

untuk memulai path, gunakan strcmp.factory.path() (strcmp adalah binary yg sudah diload) untuk 
menghasilkan path. dan path.step() untuk memulai eksekusi

setelah itu ada while loop, itu digunakan agar path melakukan step sampai jumlah path lebih dari 1
(sampai menemukan branch)

setelah menemukan branch, didalam path.successors akan berisi path2 yg aktif. path.succesors[0] akan
berisi path yg berada di branch left dan path.succesros[1] akan berisi path yg berada di branch right

kita akan menggunakan path.succesors[0], setelah itu kita tampilkan apa isi dari stdin yg menyebabkan
eksekusi program mengarah kedalam blok if.

[Image: strcmp_run.png]

## Contoh2

dicontoh 2 ini, saya mempunyai satu program lagi. programnya seperti ini
[Image: basic.png]

Tujuan kita adalah mencari nilai x, y, dan z yg akan di lewatkan ke fungsi basic agar fungsi basic 
yg mereturn angka 31337

kita tidak perlu ribet2 mereverse fungsi basic tersebut disini kita akan menggunakan angr untuk
meyelesaikannya

karna kita hanya memerlukan fungsi basic(), disini saya menggunakan factory.callable(addr) dimana addr
adalah alamat dari fungsi yg nanti dapat dipanggil melalui angr

setalah mendapatkan fungsi basic. selanjutnya kita membuat symbolic variable x, y, dan z yg nantinya digunakan untuk
memanggil fungsi basic

selanjutnya dengan s.add_constraint() digunakan untuk membatasi return value dari fungsi basic harus bernilai 31337

setelah itu digunakan s.se.any_int yg digunakan untuk mangambil nilai integer dari symbolic variable x, y, dan z

[Image: basic_run.png]

## Contoh 3

Ini adalah program crackme sederhana, skripnya seperti ini

[Image cari.png]

kalau menggunakan cara manual untuk mendapatkan passwordnya, mungkin kita akan membuat program yg mereverse fungsi
main terutama pada bagian for loop.

kali ini kita akan menggunakan angr untuk mensolve crackme ini 
