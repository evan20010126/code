# Note: node.js 

## Reference: https://www.runoob.com/nodejs/nodejs-install-setup.html

---

### 名詞介紹
- Node.js: 能夠在伺服器端運行JavaScript的開放原始碼
  > 當使用PHP編寫後端程式碼-> 需要Apache之類http服務器
- npm: Node.js預設的，軟體套件管理系統

### node.js介紹
- `var sum = _;`
  > 底線可以取得上一列計算的回傳值
- callback function
  > 一般作為函數的最後一個參數出現

  > 幾乎每個API都支援callback
  ```
  function foo1(name, age, callback) { }
  
  function foo2(value, callback1, callback2) { }
  ```
- 事件
  1. 可以透過events模組
  2. 建立EventEmitter物件
  3. 綁定事件 `.on('eventName', eventHandler)`
  4. 可以用code來觸發事件 `.emit('eventName')`
      > eventName Example:
      > 1. 'data_received'
      > 2. 'connection'
      > 3. 'error': 當建立EventEmitter物件有錯
      > 4. 'newListener': 綁定事件時會發生
      > 5. 'removeListener': 移除事件時會發生

  5. 方法
      > 1. addListener(event, listener)
      > 2. on(event, listener)
      > 3. once(event, listener)
      > 4. removeListener(event, listener)
        `eventEmitter.removeListener('connection', callbackfunction);`
      > 5. removeAllListeners([event])

  6. Buffer類，專門放置二進制數據的緩衝區
      1. 提供JavaScript二進制數據類型(可用於處理TCP stream|file stream)
      2. 創建方式
          ```js
          /* 1.
          對內存的權限操作較大，會擷取到一些敏感訊息
          */
          const buf = new Buffer();
          const buf = Buffer.alloc(size) //宣告固定長度的buffer

          /* 2. */
          const buf = Buffer.from(array) // 設定初始值為該array的buffer
          const buf = Buffer.from(buffer)
          const buf = Buffer.from(string, [encoding])
          const buf = Buffer.allocUnsafe(size) // 宣告固定長度的Buffer
          ```
      3. 寫入Buffer
          ```js
          buf.write(string, offset, len, encoding)
          // return 實際寫入的大小
          // optional: offset, len, encoding
          // offset: 寫入的index; default為0
          // len: 寫入的字數; default為buffer.length
          // encoding: default為'utf8'
          ```
      4. 讀取Buffer內資料
          ```js
          buf.toString(encoding, start, end)
          // return string
          // encoding default: 'utf8'
          // start default: 0
          // end default: buffer的尾

          /*取出元素*/
          buf[index]
          ```
      5. Buffer轉Json
         ```js
         buf.toJSON()
         ```
      6. 相關方法
         ```js
         /* Buffer合併 */
         Buffer.concat(list[buffer1, buffer2], 合併後buffer總長度)
         
         /* Buffer比較 */
         buf.compare(otherBuffer)
         // return int
         
         /* Buffer複製 */
         buf.copy(targetBuffer, targetStart_num, sourceStart_num, sourceEnd_num)
         // targetStart_num: default 0
         // sourceStart_num: default 0
         // sourceEnd_num: default buffer.length

         /* Buffer裁減 */
         buf.slice(start, end)

         /* Buffer填充 */
         buf.fill(value, offset, end)
         ```

      7. 支持的編碼
          1. 'ascii'
          2. 'utf8'
          3. 'utf16le'
          4. 'base64'
          5. 'hex'
  7. Node.js Stream
      1. Stream四種類型
          - Readable
          - Writble
          - Duplex: 可讀可寫
          - Transform
      2. 常用事件
          - 'data': 當有數據可讀時觸發。
          - 'end': 沒有更多的數據可讀時觸發。
          - 'error': 在接收和寫入過程中發生錯誤時觸發。
          - 'finish': 所有數據已被寫入到底層系統時觸發。
      3. 讀Stream
         ```js
          // 菜鳥教程範例
          var fs = require("fs");
          var data = '';

          // 創建可讀流
          var readerStream = fs.createReadStream('input.txt');

          // 設置編碼為utf8。
          readerStream.setEncoding('UTF8');

          // 處理流事件--> data, end, and error
          readerStream.on('data', function(chunk) {
            data += chunk;
          });

          readerStream.on('end',function(){
            console.log(data);
          });

          readerStream.on('error', function(err){
            console.log(err.stack);
          });
          console.log("程序執行完畢");
         ```
      4. 寫入stream
         ```js
          //菜鳥教程範例
          var fs = require("fs");
          var data = '菜鳥教程官網地址：www.runoob.com';

          // 創建一個可以寫入的流，寫入到文件output.txt 中
          var writerStream = fs.createWriteStream('output.txt');

          // 使用utf8 編碼寫入數據
          writerStream.write(data,'UTF8');

          // 標記文件末尾
          writerStream.end();

          // 處理流事件--> finish、error
          writerStream.on('finish', function() {
              console.log("寫入完成。");
          });

          writerStream.on('error', function(err){
            console.log(err.stack);
          });

          console.log("程序執行完畢");
         ```
      5. 傳遞stream
         ```js
         readerStream.pipe(writerStream);
         ```

















### npm介紹
> user可npm服務器下載別人/上傳編寫的第三方模組到本地端使用
- 查詢
  > npm help\
  > npm help \<command>

- 升級版本
  > npm install npm -g

  > -g代表全域安裝

- 安裝模組
  > 指令:\
  > npm install <ModuleName>\
  > npm uninstall <ModuleName>\
  > npm update <ModuleName>\
  > npm list -g- g 可看查全域安裝模組\
  >> 若要自創模組，需要Package.json文件
  >> 1. npm init 生成package.json
  >> 2. npm adduser 在npm中註冊用戶
  >> 3. npm publish 發布
  >> 4. npm unpublish <package>@<version>

- 模組介紹
  1. web框架模塊: express

  
- Package.json屬性說明
  1. name: 模組名稱
  2. version: 版本
  3. description: 敘述
  4. homepage: 官網
  5. author: 作者
  6. contributors: 貢獻者
  7. dependencies: 相關的模組
  8. repository: source code存放地方的類型
  9. main: 指定index文件，默認為index.js
  10. keywords: 關鍵字
  
