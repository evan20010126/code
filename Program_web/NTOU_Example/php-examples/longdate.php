<?php //longdate.php
  function longdate($timestamp)
  {
    return date("l F jS Y", $timestamp);
  }

  echo longdate(time()) . "<br>";
  echo longdate(time() - 17 * 24 * 60 * 60);
?>
