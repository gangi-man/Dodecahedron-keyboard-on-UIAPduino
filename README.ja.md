# 概要
ドデカヘドロンキーボードは正十二面体形状のUSBキーボードです。

エルゴノミクスに基づいたデザインで高速なタイピングを可能にします。

このプロジェクトは[rv003usb](https://github.com/cnlohr/rv003usb) を元に作られています。

[![The world cheapest DIY Leverless](https://markdown-videos-api.jorgenkh.no/url?url=https%3A%2F%2Fyoutu.be%2F7mj5RYsmdnM)](https://youtu.be/7mj5RYsmdnM) <img src="/images/dodecahedron-keyboard-photo.jpg" height="180px">

# ハードウェア
回路図通りキースイッチをピンとGNDの間に入れます。

WCH-LinkE (writer) 用のピン(GND/5V/SWIO)に接続用ピンを立てます。

<img src="/images/controller-circuit.png" height="400px">

# 3D Model
このプロジェクトで使われるモデルは[Thingiverse](https://www.thingiverse.com/thing:7426392) にあります。

# ビルド方法
## 事前準備
このプロジェクトは[ch32fun SDK](https://github.com/cnlohr/ch32fun) とWCH-LinkE (ライター)を使います。

この[this page](https://github.com/cnlohr/ch32fun/wiki/Installation) に従って必要なツールをインストールしてください。

## レポジトリ
このレポジトリをClone して以下のコマンドでsubmodule を初期化してください。
```
git submodule update --init --recursive
```

## ビルド・書き込み
PCとWCH-LinkE を接続し、WCH-LinkE からUIAPduinoのピン(5V/GND/SWIO)を繋ぎます。

以下のコマンドでビルドと書き込みができます。
```
cd src
make
make flash
```

# 使い方
プログラムを書き込んだ後、UIAPduinoのUSB-C ポートをPCに接続するとキーボードとして使うことができます。

# 部品表
* [UIAPduino](https://www.uiap.jp/uiapduino/pro-micro/ch32v003/)
* キースイッチ x 11
* キーキャップ x 11
* タッピングねじ x 2
