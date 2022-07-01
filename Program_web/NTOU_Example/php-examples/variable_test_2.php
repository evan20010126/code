<?php // variable_test_2.php
  $temp = "The date is ";
  echo longdate($temp, time());
  function longdate($text, $timestamp)
  {
    return $text . date("l F jS Y", $timestamp);
  }
?>