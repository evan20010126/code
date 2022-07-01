<?php // variable_test_1.php
  $temp = "The date is ";
  echo longdate(time());
  function longdate($timestamp)
  {
    return $temp . date("l F jS Y", $timestamp);
  }
?>