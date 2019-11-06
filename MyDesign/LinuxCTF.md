---
title: 20191016 - Linux        # 簡報的名稱
tags: CDPA   # 簡報的標籤
author: Sophie Shin
date: 2019/10/19
slideOptions:        # 簡報相關的設定
  theme: solarized   # 顏色主題
  transition: 'fade' # 換頁動畫
robots: noindex, nofollow # 透過"noindex, nofollow 防止任何搜尋引擎索引您的筆記
---

<!-- .slide: data-background="https://i.imgur.com/LxxkwLE.jpg" -->

<!--
pre code .gutter.linenumber{ 
    text-align: right;
    position: relative; 
    display: inline-block; 
    cursor: default; 
    z-index: 4; padding: 0 8px 0 0; 
    min-width: 20px; 
    box-sizing: content-box; 
    color: #afafaf; 
    border-right: 3px solid #6ce26c; }

pre code .code {
  height: 100%;
  max-height: 100%;
  box-sizing: border-box;
  background: #E2A8FF
  color: #FF0000;
} -->


## <span style="color:#FF8888"> CDPA - Linux & CTF</span>

<span style="color:#FFCCCC">@ Sophie Shin</span>


---

## 基本指令

----

### 查看 / 改變 目錄

|   指令    | 指令敘述 |
| :------: | :------: |
| pwd      | 印出目前工作目錄 |
| cd       | 改變目錄     |


----

### cd

|   指令  | 指令敘述 |
|:------:| :------: |
| `$ cd ..`  | 返回上一個目錄|
| `$ cd ~ `  | 到使用者目錄 |
| `$ cd / `  | 回到根目錄 |

----

### 根目錄有什麼?
* [Linux檔案系統結構](http://blog.shiami.info/peterliu/28-linux%E6%AA%94%E6%A1%88%E7%B3%BB%E7%B5%B1%E6%A8%99%E6%BA%96/)

![](https://i.imgur.com/qt4JZiZ.png)

----


### 建立/刪除 目錄/檔案

|   指令    | 指令敘述 |
| :------: | :------: |
| `$ ls`   | 印出該目錄有什麼檔案 |
| `$ touch f1 f2 f3`    | 建立檔案f1,f2,f3 (可放多個參數) |
| `$ rm filename` | 移除filename檔案    |
| mkdir dirname   | 建立dirname目錄  |
| rmdir dirname  | 移除dirname目錄   |

----

### 移動 / 修改 / 複製 / 顯示 檔案

|   指令    | 指令敘述 |
| :---------: | :------: |
| `$ mv f1 /path/Dir` | 將檔案移動到其他目錄 |
| `$ mv f1 f2`  |  修改檔名 (將f1檔名改成f2) |
| `$ cp f1 f2` | 複製檔案 (將f1檔案複製給f2)|
| `$ cat filename` | 印出檔案內容   |

----

### 不知道指令做什麼該怎麼辦
<br>

|   指令    | 意義 |
| :------: | :------: |
| `指令` -h   | help  |
| man  `指令`  | 顯示該指令的手冊(manual)  |
| tldr `指令`  | 長話短說 (Too Long; Didn't Read) |

----

#### 壓縮與解壓縮 (僅參考不用記)

| 檔案類型  | 壓縮指令 | 解壓縮指令 |
|:--------:|:------:|:------:|
| `.tar`   | `tar cvf f.tar file` | `tar xvf f.tar` |
| `.zip`   | `zip -r f.zip Dir` |  `unzip f.zip`  |
| `.gz`    | `gzip file` | `gzip -d file.gz` |
| `.rar`   | `rar a file.rar file` | `rar e file.rar` |

----


### sudo：super user do 最高權限執行

* `$ sudo apt-get install 套件名稱`
    * 沒有預先安裝的程式，就要使用
* `$ sudo apt-get update`
    * 下載且更新到最新的軟體"清單"，並非軟體
* `$ sudo apt-get upgrade` 
    * 依照最新的軟體清單，將本機現有的軟體全部做更新
* `$ sudo su` 以root身分執行shell

---

## CTF 常用指令
<br>

----


### ls -al 印出檔案特徵及隱藏檔

![](https://i.imgur.com/CdLZPNq.png)

----

### file 檔案類型


| Column 1 | Column 2 | 
|:-------- | :--------:| 
| `$ file cat.jpg`  | JPEG image data  |
| `$ file run.exe`  | executable for MS Windows |
| `$ file Desktop` | directory |
| `$ file hello.py` | Python script |
| `$ file name.txt` | ASCII test |

----

### find 找檔案

* find 遞迴搜尋所有目錄和檔案
* 可根據檔案特徵去做搜尋
    * 大小 (-size 1234c)
    * 類型 (-type d/f)
    * 檔名 (-name *.cpp)
    * 身分(-user, -group)
    * 修改時間 (-mtime 5)

----

### grep 找字串

* `$ grep "字串內容" filename1 filename2 filename3`
* `$ grep "字串內容" *` 對所有檔案搜尋特定的字串內容
* `$ grep -r "CDPA"` 遞迴搜尋該目錄下(含子目錄)所有檔案

----

### strings

* Find printable strings in an object file or binary
* `strings filename`


----


### chmod 更改權限
![](https://i.imgur.com/PhJvF78.png)

* 九種權限
    * 3種身分
    * 3種檔案權限

----

### chmod 更改權限

| 權限 |     意涵     | 　 | 身分 |
|:-:|:--------------:|-|-|
| r | **R**ead 可讀   | 　| user (擁有者)  |
| w | **W**rite 可寫  | 　| group (群組)   |
| x |e**X**ecute 可執行| 　| others (非群組)|

----

### chmod 更改權限

* $ chmod +r filename
    * 檔案：可印出來
    * 可列出目錄中的檔案名稱，等同可使用ls
* $ chmod +w filename
    * 檔案：可修改檔案內容
    * 該目錄下：可建立、刪除、改名檔案
* $ chmod +x filename
    * 檔案：從不可執行變可執行
    * 目錄：**可以進入該目錄之中!!!**

----


### Linux 好潮，想學習有什麼建議?
<br>

* 練英文 QQ
* **預設作業系統請改用Linux** :wink::wink::wink:
* [鳥哥私房菜](https://linux.vbird.org/)
* [Linux Wargame：Overthewire](https://overthewire.org/wargames/)


---

### 實戰練習

**指令都能在slide上找到**
* cd /home/cdpa/Desktop/1016/2019cdpa/
* 從第一題開始寫，每一題解完會有一組密碼
* 該組密碼為下一題的解密密碼

----

### Problem 1

* Hint：ls、pwd、cd、file、cat、chmod、bash
* man 和 tldr 是你的好幫手
* `$ ccencrypt filename` 檔案加密
  `$ ccdecrypt filename` 檔案解密

----

### Problem 2
* Hint1：ls、pwd、cd、file、cat、grep、pipe
* Hint2：可透過`$ 指令1 | 指令2` 得到密碼
    * [pipe怎麼用?](https://ryanstutorials.net/linuxtutorial/piping.php)
* Hint3：題目即提示 (很重要!!!)
* man 和 tldr 是你的好幫手

----

### Problem 3

* 提示在題目裡
* Hint：ls、pwd、cd、file、cat、grep
* man 和 tldr 是你的好幫手

----

### Problem 4

* 提示在題目裡
* Hint：ls、pwd、cd、file、cat、grep、find
* man 和 tldr 是你的好幫手

----

### Problem 5

* Hint：ls、pwd、cd、file、cat、chmod
* man 和 tldr 是你的好幫手
* 參考[講義內容](https://hackmd.io/@sophiexin036/CDPALinuxCTF#/2/7)

----

### Problem 6

* Hint：ls、cd、mv、file、cat
* man 和 tldr 是你的好幫手

----

### Problem 7
* Hint：ls、cd、**mv**、**file**、cat
* man 和 tldr 是你的好幫手
* **可能會改到副檔名**
* 參考 [壓縮與解壓縮](https://hackmd.io/@sophiexin036/CDPALinuxCTF#/1/7)

---

## Linux wargame
### Writeup 詳細解法

----

### Problem 1
1. `ls` 印出目錄下的檔案
2. `file p1`後，發現是ASCII text檔案
3. 因此使用`cat p1`去印出題目的要求
4. 使用`ls -al`指令印出隱藏檔案，發現有\.run.sh檔案
5. How to run shell script? (兩種方式)
    * bash .run.sh
    * chmod +x .run.sh; ./.run.sh
6. 執行完後即會拿到密碼，作為第二題的解密金鑰

----

### Problem 2
1. 輸入`ls`後發現有==CDPA.cpt==檔，而 **\.cpt** 是一種加密過的檔案類型
2. 因此按照第一題所提供的Hint2指令去解密檔案
    * 輸入`ccdecrypt CDPA.cpt`後 CDPA.cpt 變成 CDPA，即完成解密
3. 輸入`file CDPA`發現是ASCII text，因此輸入`cat CDPA`查看檔案有什麼內容
4. 看完會猜到只有唯一一組才是正確密碼，並由提示得知==題目即提示==，因此CDPA為關鍵字串
5. 輸入`grep "CDPA" CDPA` 表示對CDPA檔案搜尋"CDPA"字串，即可得知解密金鑰


----

### Problem 3
1. 輸入`ls`發現仍要解密，並輸入`ccdecrypt hint.cpt`後，做`file hint` 分析，發現是ASCII text，因此輸入`cat hint`得到提示
2. 輸入`ls -al`即可得到隱藏目錄.CDPA0到.CDPA10，並`cd .CDPA0`去查看子目錄有什麼檔案
3. `file CDPA*`分析子目錄所有檔案後發現都是文字檔，因此輸入`cat CDPA0`，會發現許多有知識但對這題沒意義的檔案:smile:

----

### Problem 3 (2)

4. 分析後會發現許多檔案都是英文字母構成，因此可猜測解密金鑰就在裡面
5. 關鍵字是什麼？從提示二 **We are CDPA!** 可得知可能是 **We are CDPA!** 或是 **CDPA**
6. 回到p3目錄，並且輸入`grep -r "CDPA"`，即可發現解密金鑰

----

### Problem 4
1. 輸入`ls`發現有很多檔案，並先輸入`ccdecrypt hint.cpt`解密hint.cpt，`file hint`後發現仍是ASCII test
2. `cat hint`發現提示給是==檔案特徵==，且cd 每個目錄都有許多ASCII text，因此從find指令下手
3. 輸入`find -size 4052c` 發現給了三個子路徑的檔案
4. 一一輸入`cat ./CDPA8/CDPA4`和`cat ./CDPA7/CDPA12` 和`cat ./CDPA6/CDPA16`，即可找到有個pass以及解密金鑰

----

### Problem 5
1. ls 並將p5.cpt解密
2. `file p5` 發現是ELF檔案，即Linux的執行檔
3. 輸入`./p5`執行後發現不能執行，因此需要==改變權限==
4. 輸入`chmod +x p5`，讓原本不能執行的p5變成可執行
5. 執行p5，輸入`./p5` 即可成功取得解密金鑰

----

### Problem 6
1. ls 並輸入`ccdecrypt md5sum.cpt`做解密
2. `file md5sum`，發現是ASCII text檔案，並`cat md5sum`，得到 **Do you know md5sum?** 提示
3. 若知道md5sum就會了解如何得到金鑰，若不會必須google
> 若要打好CTF底子，多多善用google
4. 從google後得知，md5sum是Linux指令，因此`man md5sum`，了解 md5sum的怎麼執行
5. `md5sum md5sum` 即可取到解密金鑰

----

### Problem 7
* ls 沒東西，ls -al 試試看，發現有 `.pt.cpt`
* 解密並`file .pt`是==tar壓縮檔==，因此需先`mv .p7 p7.tar`讓指令能夠辨識是tar壓縮檔，再輸入`tar xvf p7.tar`解壓縮
* ls -al後發現壓縮出 \.p7檔案，`file .p7`發現是==gzip==壓縮檔案，因此需先`mv .p7 p7.gz`讓指令能夠辨識是gz壓縮檔，再輸入`gzip -d p7.gz`解壓縮
* ls後發現p7，之後`file p7`發現是ASCII test
* `cat p7`印出 Welcome to CDPA 後即為結束 :smile: :congratulations: :+1: 

----

# Q&A

---