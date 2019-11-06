---
title: 20191016 - Python & CTF        # 簡報的名稱
tags: CDPA   # 簡報的標籤
author: Sophie Shin
date: 2019/10/19
slideOptions:        # 簡報相關的設定
  theme: solarized   # 顏色主題
  transition: shrink # 換頁動畫
---

<!-- .slide: data-background="https://i.imgur.com/2xpqca0.jpg" -->


## <span style="color:#66FFFF"> CDPA - Python & CTF</span>

<span style="color:#66FFFF">@ Sophie Shin</span>


---

### [CTF：Capture The Flag](https://www.ithome.com.tw/news/102952)
* 藉由漏洞拿到Flag的競賽方式
* 練習資安攻擊手法的實務平台
* 藉由題目學習資安技術與工具
* 學校只教資安理論
* 而CTF學的是資安實務

----

### [競賽方式](https://www.itread01.com/content/1546804836.html)
* 解題模式（Jeopardy）
* 攻防模式（Attack-Defense）
* King of Hill

----

### 六大題型
* Web 網頁
* Pwn 弱點或漏洞分析
* Reverse Engineering 逆向工程
    * PWN、Reserve偏重對組合語言、反組譯的理解
* Crypto 加解密
    * 偏重數學、演算法
* Forensics 數位鑑識
* Misc 綜合

----

### 各大競賽
* MyFirstCTF
    * 初入資安領域之打競賽的好選擇
* [AIS3](https://ais3.org/)
    * 免費且為期一週的培訓課程
    * 裡面很多資安高手&大神 !!
* 線上賽
    * [CTFtime](https://ctftime.org/)：紀錄全世界CTF比賽資訊

----

### 練習網站
* [PicoCTF](https://2018game.picoctf.com/news)：新手導向
* [Hackme CTF](https://hackme.inndy.tw/)：六大類題目都有
* [CTFtime](https://ctftime.org/)

----

### 具備技能 (以Crypto為主)

---

### Linux
* [上週講義](https://hackmd.io/xA2sJfu2R_2Ribcib1TDgA)
* [Overthewire](https://overthewire.org/wargames/)

----

### Python
* 套件齊全
* 版本建議用 Python 3.6

----

### 離散數學
* 本次課程不會用到太抽象的數學
* 現代密碼學


----

### 密碼學
* [NTU 陳君明教授 密碼學導論](https://ceiba.ntu.edu.tw/modules/index.php?csn=725b8b&default_fun=syllabus&current_lang=chinese)

---

## 密碼學

----

### 古典密碼學
* 加密手法
    * 替換式加密 Substitution cipher
    * 移位式加密 Transposition Cipher

----

### 替換式加密
![](https://i.imgur.com/L4pelOq.png)
* 表格轉換、內容改變
* 凱薩密碼 (Caesar Cipher)
    * `$ tr A-Za-z N-ZA-Mn-za-m "一串訊息"`
* 維吉尼亞密碼 (Vigenère Cipher)
    * 開始有了**密鑰**的概念

----

### 移位式加密
* 重新排列 (改變位置)
* 內容不變
* Rail-fence Cipher (籬笆加密)
 m (明文) = WEGOTOKTVATTHREEPM
 k (金鑰) = 3(層)
 c (密文) = WTVHPEOOTATREMGKTE
![](https://i.imgur.com/oQ685Ow.png)

---

## 編碼

----

### ASCII
* 針對字母、數字、英式符號所進行的編碼標準
* A的ASCII為65 (十進位)
* a的ASCII為97 (十進位)

----

### [Unicode](https://www.online-toolz.com/tools/text-unicode-entities-convertor.php)
* 彙整了世界上各國語言的編碼標準
* 漢字、日文、韓文等許多國家文字都涵蓋
* 大部分軟體採用

----

### 其他編碼

* [太多了](http://blog.neargle.com/SecNewsBak/drops/CTF%E4%B8%AD%E9%82%A3%E4%BA%9B%E8%84%91%E6%B4%9E%E5%A4%A7%E5%BC%80%E7%9A%84%E7%BC%96%E7%A0%81%E5%92%8C%E5%8A%A0%E5%AF%86%20.html)

---

### Python3
* 套件：Pwntools
* `sudo apt install python3-pip`
* `sudo pip3 install git+https://github.com/arthaud/python3-pwntools.git`
* 本次課程環境已經完成設定，上面指令無需使用~
* [doc](https://python3-pwntools.readthedocs.io/en/latest/about.html)：詳細手冊

---

### Python 基礎

----

### 印出
* **Debug的好方法**!!!!!!!!!!! (重要)
* print() 預設會直接換行
```python=
print("Hi~我們是CDPA :D")
a = 2
print(a)
print("Output: ", a)
```
```
Hi~我們是CDPA :D
2
Output: 2
```

----

### 引入模組、函式庫
從pwn模組引入所有函式( **\*** )
```python=
from pwn import *
```

----

### 解碼 decode()
#### 將 bytes型態字串 轉成 一般 字串
```python=
b'2019/10/15'.decode() # 回傳  '2019/10/15' 字串 (屬於一般字串型態)
b'abc'.decode() # 回傳 'abc'
```

----

### string和bytes之間的轉換關係
str–>encode()–>bytes–>decode()–>str
![](https://i.imgur.com/guZ5Fsu.png)


----

### eval()：計算字串裡面的運算式
```python=
eval括弧內不能有 "=" 的符號!!!!!!!!!!
eval("1+1") # 回傳2
eval("9*9+1000") # 回傳1081
eval("1+1=") # error
eval("1+1=?") # error
```

---

### Python 溝通
程式與程式之間的溝通

----

### 執行程式
path：相對路徑/絕對路徑
* 每個檔案的位置路徑不會相同，善用 `pwd`指令查看所在的路徑位置
```python=
# 將p變數想像成遙控器(溝通者)，他有很多功能可以做
p = process("/home/cdpa/Desktop/program") 
```
* 若要執行檔案與所寫的python程式在**同個目錄**下，就只需要所執行的檔案名稱
```python=
# 若執行檔名稱叫 excuseme，則下列兩者皆可用 (二選一)
p = process("./excuseme")
p = process("excuseme")
``` 

----

### 建立連線
建立連線，並且指派給 connect的變數
將connect想像成遙控器，他有很多功能可以做
```python=
connect = remote(address, port) # 建立連線
```

----

### 傳送訊息
將connect想像成遙控器，他可以傳送訊息
```python=
connect.send("字串") # 傳送訊息但不換行
connect.sendline("字串") # 一次傳送一行訊息
```

----

### 接收訊息
* 回傳是 bytes的資料型態
```python=
connect.recv() # 預設接收4096 Bytes的bytes型態，可在括弧內調整參數大小
connect.recvline() # 一次接收一行
connect.recvuntil("字串", drop=True) # 接收訊息直到某個字串出現
```

----

### 互動
取得對方的shell才可使用 (PWN類型題目)
```python=
connect.interactive()
```
* 本次課程不會用到

----

### 關閉連線 / 關閉程式
變數名稱.close()
```python=
connect.close()
p.close()
```

---

## 實戰練習
[題目檔連結](https://reurl.cc/K6MOeg)
1. 寫程式執行程式
2. 寫程式完成遠端傳送的內容

----

## Problem 1
* 一個執行檔
* 寫一個python檔來完成
* 無法用暴力解 ^^
* :smile: :smile: :smile:

----

## Problem 2
```python=
$ nc 2019shell1.picoctf.com 49914
```
* 上面是一串指令，可以複製到ubuntu terminal試試看
* 可以暴力解，但寫程式更方便

---

### CTF題目不會寫怎麼辦? 看Writeup
* [Web - Orange](http://blog.orange.tw/)
* [Pwn - Angelboy](http://angelboy.tw/)
* [Crypto - Maojui](https://maojui.me/)
* 其他各國writeup，自行google :smile:

----

### 資源

* [各大網站整理](https://gotyour.pw/resources.html)
* [pwntool 教學](http://brieflyx.me/2015/python-module/pwntools-intro/)
* [pwntool doc](https://python3-pwntools.readthedocs.io/en/latest/about.html)
* [CTF - Wiki](https://ctf-wiki.github.io/ctf-wiki/)

---

# Q&A

----