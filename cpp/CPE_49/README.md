# CPE_49 - Website

- [CPE_49 Question web](https://cpe.cse.nsysu.edu.tw/environment.php)

- [CPE_49 Solution web](https://jennaweng0621.pixnet.net/blog/post/403629785-cpe%E9%A1%8C%E7%9B%AE%E7%9B%AE%E9%8C%84%E5%8F%8A%E8%A7%A3%E7%AD%94) 

- [Examine web - zero judge](https://zerojudge.tw/)

<br>
<br>

# CPE_49 - Learning Skill

## 萬用標頭檔
`#include <bits/stdc++.h>`

---

## 加速
[參考網址](https://chino.taipei/note-2016-0311C-%E7%9A%84%E8%BC%B8%E5%87%BA%E5%85%A5cin-cout%E5%92%8Cscanf-printf%E8%AA%B0%E6%AF%94%E8%BC%83%E5%BF%AB%EF%BC%9F/)
    
`std::ios_base::sync_with_stdio(false);`
        
        
- 控制是否兼容stdio。C++為了兼容Ｃ, 保證程序在使用std::printf和std::cout的時候不發生混亂, 將輸出流綁在一起。
- 也就是C++標準streams(cin,cout,cerr)與相應的Ｃ標準程式庫文件(stdin,stdout,stderr)同步, 使用相同的stream緩衝區
> 1. 默認是同步, 但同步會帶來某些不必要的負擔。
> 2. 注意要是關掉了，scanf/printf就不能用了（如果用了，而且跟cin/cout混用，可能會吃到奇怪的東西。
    
`cin.tie(NULL);`
- cin預設綁住了cout，而被綁住的ostream會在istream要輸入時被flush。
- cin/cout解綁，我們可以透過傳一個NULL（也可以用0）進入cin.tie()來讓cin綁住空的ostream。
> **為什麼要有tie這個設計呢？**

>> 我曾經看過一些說法，一種是說，因為我們有時候可能要寫一些console應用程式，
>> 如果我們要使用者輸入一些值的時候可能要先輸出一些提示訊息像是「請輸入一個數字：」然後才用cin輸入，要是上面那一句話沒有被flush到螢幕上的話，使用者就看不到了，而且你可能不想要換行，就算加<<flush也很麻煩，所以C++就設計了這樣的作法，讓你在cin前會把cout清空緩衝區。

`<< endl;`
- 實際運作:\
等於 << "\n" << flush; //flush為強制將緩衝區的資料輸出，且將緩衝區的資料清空
而cout用了一個類似優化的設計，叫作緩衝區（由作業系統實作），所有的輸出都會先進到緩衝區裡，
直到緩衝區滿了才會清空緩衝區並把字串輸出到stdout之類的輸出串流

---

## StringStream 
[參考網址 (StringStream－int和sting轉換的另一種方案與清空StringStream)](https://dotblogs.com.tw/v6610688/2013/11/08/cplusplus_stringstream_int_and_string_convert_and_clear)
- 使用:
    ```
    #include <sstream>

    stringstream ss;

    ss << [Str或Int];
    ss >> [Int或Str];
    ```
- 檢查是否轉型成功:
    ```
    if(!ss) cout << "error type" << endl;
    else cout << [轉出來的東西] << endl;
    ```
- 清空(若要沿用先前的StringStream，要先清空先前的資料):
    ```
    ss.str(""); //可以完全的把先前字串清空
    ss.clear(); //清空標示已讀到EOF的tag
    ```
- ss.str()
    ```
    cout << ss.str(); //輸出在stringstream的內容
    ``` 
- ss.str(\[Str\])
    ```
    ss.str("hello"); //可將StringStream賦值
    ```

---

## getline()
- 使用:
    ```
    #include <string>
    ```
    - 用法1:
        ```
        istream& getline(istream& is, string& str, char delim);
        ```
        - is: istream類的對象, 告訴函數有關從何處讀取輸入的流.
        - str: 字符串對象, 從流中讀取輸入後, 將輸入儲存在此對象中.
        - delim: 定界字符, 到達該字符後停止讀取進一步的輸入.
    - 用法2:
        ```
        istream& getline(istream& is, string& str);
        ```
        - Example: 讀取空格
            ```
            getline(cin, str); //讀取整行輸入, 可讀取空格
            ```
        - Example: 根據字符分割句子
            ```
            string S, T;
            getline(cin, S);
            stringstream X(S);
            while(getline(X, T, ' ')){
                cout << T << endl;
            }
            ```
            Input:\
                Hello, Faisal Al Mamun. Welcome to GfG!

            Output:\
                Hello,
                Faisal
                Al
                Mamun.
                Welcome
                to
                GfG!

---

## c/c++ Map(STL標準模組庫)
[參考文章(C++ std::map 用法與範例)](https://shengyu7697.github.io/std-map/)
> C++ std::map
> - 是一個關聯式容器(關聯式容器把鍵值和一個元素聯繫起來，並使用該鍵值來尋找元素/插入元素/刪除元素) //很像key:value
> - map is sorted relationship container. <br>-> map容器中所有的元素都會依據元素對應的鍵值(key)排序\[key為唯一\] <br> if 同樣key在insert資料 <br>-> new的資料覆蓋原本key資料
> - map的實作方式: red-black tree //保證在O(logn)搜尋插入刪除(n為元素個數)

- 使用
    - 引用
        ```
        #include <map>
        ```
    - 宣告map容器
        ```
        std::map<int, std::string> studentMap; //宣告時需宣告兩個變數類型        
        ```
    - 初始化 (以下視為有using namespace std;)
        - 第一種:
            ```
            studentMap.insert( pair<int, string>(1,"Tom"));
            //studentMap.insert(std::pair<int, std::string>(1, "Tom"));
            ```
        - 第二種:
            ```
            map<int, string> studentMap;
            studentMap[1] = "Tom";      //如果元素本來就存在會被更新成新的數值
            ```
        - 第三種:
            ```
            map<int, string> studentMap = {
                {1, "Tom"},
                {2, "Jack"},
                {3, "John"}
            };
            ```
    - map容器插入元素
        - 第一種: //像陣列
            ```
            studentMap[1] = "Tom";
            ```
        - 第二種: //用map.insert()成員函式插入元素 <<
            > different: 若key已經存在, 會回傳插入失敗的結果
                        