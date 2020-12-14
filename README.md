# LinerBot
Idea asal LinerBot adalah membina sebuah mobile robot mini yang mampu mengesan dan bergerak mengikut garisan.

Dalam proses membina LinerBot telah berlaku beberapa proses seperti ujian pendawaian motor, kalibrasi penjajaran roda kanan dan kiri dan beberapa proses lain bagi memastikan LinerBot dapat bergerak secara optimum.

Kesemua proses ini memerlukan komponen tambahan bagi memudahkan proses tersebut. Dari situ terhasil Papan Induk Kawalan LinerBot bagi memudahkan proses tersebut seperti keperluan kepada pengguna Push Button, Potentiometer dan terminal port yang lain yang boleh menambahkan fungsi LinerBot.

Papan Induk Kawalan LinerBot ini sedikit sebanyak membantu proses pembelajaran khasnya dalam pembinaan mobile robot daripada asas kepada fungsi tambahan kawalan jarak jauh dan seterusnya fungsi autonomous.

Kawalan jarak jauh boleh menggunakan Bluetooth Module seperti HC-05 atau HC-06 menggunakan terminal Bluetooth yang tersedia pada Papan Induk Kawalan LinerBot.

Mode kawalan jarak jauh juga boleh menggunakan Remote Control seperti jenis Futaba dan yang seangkatan dengannya menggunakan terminal EDGE_L dan EDGE_R sebagai GPIO1 dan GPIO2 signal input. Ini menjadikan Linerbot boleh dikawal dengan alat kawalan radio frekuensi yang lebih advance.

Kesediaan terminal bagi sensor juga membolehkan LinerBot sama ada digunakan untuk robot yang bergerak mengikut garisan atau yang boleh mengelak objek malah boleh juga digunakan sebagai robot sumo.

Kepelbagaian ini semua adalah bergantung pada kreativiti programming yang dibuat yang sememangnya sesuai digunakan untuk tujuan pembelajaran mobile robot atau autonomous robot.

- Buzzer menggunakan D8
- Push Button menggunakan D2 (INPUT_PULLUP)
- Potentiometer/Trimmer menggunakan A0

Bahan untuk membina LinerBot :
  - Chassis (3D Printed main_body.stl)
  - M3 x 6mm self tapping screw

Komponen utama yang perlu dipasang pada Papan Induk Kawalan LinerBot ini adalah :
  - Arduino Nano (penggunaan Maker Nano akan menjadikannya lebih menarik)
    (https://my.cytron.io/p-maker-nano-simplifying-arduino-for-projects?search=maker&description=1)
  - Motor Driver TB6612FNG
    (https://my.cytron.io/p-tb6612fng-dual-channel-1p2a-motor-driver-presoldered-header?search=tb6612&description=1)
  - Metal Micro GearMotor (dicadangkan 6V 600rpm)
    (https://my.cytron.io/p-6v-600rpm-medium-power-dc-micro-metal-gearmotor)
  - LiPo Battery 7.4V
    (https://my.cytron.io/p-lipo-battery-7.4v-450mah)
  - Mini Wheel 34x7mm
    (https://my.cytron.io/p-mini-wheel-34x7mm-for-n20-gear-motor?search=wheel&description=1)

Untuk fungsi Bluetooth RC memerlukan komponen tambahan Bluetooth Module sama ada :
  - HC-05 atau HC-06

Untuk fungsi robot mengikut garisan :
  - Maker Line
    (https://my.cytron.io/p-maker-line-simplifying-line-sensor-for-beginner?search=maker%20line&description=1)
  atau
  - LSS05
    (https://my.cytron.io/p-auto-calibrating-line-sensor?search=lss05&description=1)
  tambahan
  - Maker Reflect
    (https://my.cytron.io/p-maker-reflect-simplifying-ir-reflectance-sensor-for-beginner?search=sumo&description=1&src=search.list)

Untuk fungsi robot sumo atau robot pengelak objek dicadangkan menggunakan :
  - Maker Object
    (https://my.cytron.io/p-maker-object-simplifying-object-sensor-for-beginner?search=maker%20object&description=1)
  atau
  - HC-SR04 Ultrasonic Sensor
    (https://my.cytron.io/p-5v-hc-sr04-ultrasonic-sensor?search=ultrasonic&description=1)

Untuk fungsi RC Radio Frekuensi boleh menggunakan FlySky 3 Channels RC Radio Transmitter and Receiver dan yang seangkatan dengannya
(https://my.cytron.io/p-flysky-3-channels-rc-radio-transmitter-and-receiver)
