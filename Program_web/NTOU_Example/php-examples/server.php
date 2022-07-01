<?php
  echo $_SERVER['PHP_SELF'];
  echo "<br>";
  echo $_SERVER['SERVER_NAME'];
  echo "<br>";
  echo $_SERVER["SERVER_SOFTWARE"];
  echo "<br>";
  echo $_SERVER['HTTP_USER_AGENT'];
  echo "<br>";
  echo $_SERVER["REQUEST_TIME"];
  echo "<br>";
  if (isset($_SERVER['HTTP_REFERER'])) echo $_SERVER['HTTP_REFERER'];
?>