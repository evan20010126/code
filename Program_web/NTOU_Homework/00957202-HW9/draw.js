// Fig. 13.4: draw.js 
// A simple drawing program. 
 //initialization function to insert cells into the table
var store_arr;
function delta(){ //判斷是否第一次進入 (若為第一次進入 設定white)
   if (localStorage.length == 0){
      store_arr = [];
      for (var i = 0 ; i < 100; ++i){
         store_arr.push([]);
      }
      for (var i = 0; i < 100; ++i){
         for (var j = 0; j < 100; ++j){
            store_arr[i].push("white");
         }
      }
      var store_obj = {"arr": store_arr};
      localStorage.setItem("key01", JSON.stringify(store_obj));
   }else{ //若local內有東西 也要初始化store_arr 不然下次載入store_arr為undefined 無法[][]
      store_arr = [];
      for (var i = 0 ; i < 100; ++i){
         store_arr.push([]);
      }
      var key = localStorage.key(0);
      var obj = JSON.parse(localStorage.getItem(key)); //拿到整個物件
      for (var i = 0; i < 100; ++i){
         for (var j = 0; j < 100; ++j){
            
            store_arr[i].push(obj["arr"][i][j]);
         }
      }

   }
}

function clearALL(){
   var tds = document.getElementsByTagName("td");
   for (var i = 0; i < 100; ++i){
      for (var j = 0; j < 100; ++j){
         store_arr[i][j] = "white";
      }
   }
   var store_obj = {"arr": store_arr};
   localStorage.setItem("key01", JSON.stringify(store_obj));
   for (var i = 0; i < tds.length; i++){
      tds[i].setAttribute("class", "white");
   }
}

function createCanvas()
{
   delta();
   var side = 100;
   var tbody = document.getElementById( "tablebody" );
   for ( var i = 0; i < side; ++i )
   {
      var row = document.createElement( "tr" );
       
      for ( var j = 0; j < side; ++j )
      {
         var cell = document.createElement( "td" );
         var key = localStorage.key(0);
         var obj = JSON.parse(localStorage.getItem(key)); //拿到整個物件
         cell.setAttribute("class", obj["arr"][i][j]); /**/
         cell.class = i.toString();
         cell.id = j.toString();
         // store_arr[i].push("white");
         row.appendChild( cell );
      } // end for

      tbody.appendChild( row );
   } // end for
   /*事件clear*/
   document.getElementById("clear_B").addEventListener("click",clearALL);
   /**/

   // register mousemove listener for the table
   document.getElementById( "canvas" ).addEventListener( 
      "mousemove", processMouseMove, false );

} // end function createCanvas

// processes the onmousemove event
function processMouseMove( e )
{        
   if ( e.target.tagName.toLowerCase() == "td" )
   {
      // turn the cell blue if the Ctrl key is pressed
      if ( e.ctrlKey )
      {
         e.target.setAttribute( "class", "blue" );
         store_arr[parseInt(e.target.class)][parseInt(e.target.id)] = "blue";
      } // end if

      // turn the cell red if the Shift key is pressed
      if ( e.shiftKey )
      {
         e.target.setAttribute( "class", "red" );
         store_arr[parseInt(e.target.class)][parseInt(e.target.id)] = "red";
      } // end if
      if (e.altKey){
         e.target.setAttribute("class", "black");
         store_arr[parseInt(e.target.class)][parseInt(e.target.id)] = "black";
      }
      if (e.buttons == 1){
         e.target.setAttribute("class", "white");
         store_arr[parseInt(e.target.class)][parseInt(e.target.id)] = "white";
      }
      //document.getElementById("canvus");
      //console.log(store_arr);
      var store_obj = {"arr": store_arr};
      localStorage.setItem("key01", JSON.stringify(store_obj));
   } // end if
} // end function processMouseMove
window.addEventListener( "load", createCanvas, false );

/*************************************************************************
* (C) Copyright 1992-2012 by Deitel & Associates, Inc. and               *
* Pearson Education, Inc. All Rights Reserved.                           *
*                                                                        *
* DISCLAIMER: The authors and publisher of this book have used their     *
* best efforts in preparing the book. These efforts include the          *
* development, research, and testing of the theories and programs        *
* to determine their effectiveness. The authors and publisher make       *
* no warranty of any kind, expressed or implied, with regard to these    *
* programs or to the documentation contained in these books. The authors *
* and publisher shall not be liable in any event for incidental or       *
* consequential damages in connection with, or arising out of, the       *
* furnishing, performance, or use of these programs.                     *
*************************************************************************/