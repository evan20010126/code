<?php // string_test.php 請嘗試看看結果
  $username = "Fred Smith";
  echo $username."<br>";
  $current_user = $username;
  echo $current_user."<br>";
  $userOutput1 = "I am $current_user";
  $userOutput2 = 'I am $current_user';
  echo $userOutput1."<br>";
  echo $userOutput2."<br>";
?>
