<?php // multiple_lines.php
  $author = "Brian W. Kernighan";

  echo <<<_HI
  <p style="font-family:Arial;font-size:150%;font-style:italic">
  Debugging is twice as hard as writing the code in the first place.<br>
  Therefore, if you write the code as cleverly as possible, you are,<br>
  by definition, not smart enough to debug it.<br><br>
  
  - $author.</p>
_HI;
?>
