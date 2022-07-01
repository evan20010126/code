<?php //explode.php
  $temp = explode(' ', "This is a sentence with seven words");
  print_r($temp);
  echo "<br>";
  foreach($temp as $token)
    echo $token."<br>";
?>
