<?php // operator_test.php 請嘗試看看結果
  $a = "5";
  $b = "3";
  echo (+$a)."<br>";      // Identity
  echo (-$a)."<br>";      // Negation
  echo ($a + $b)."<br>";  // Addition
  echo ($a - $b)."<br>";  // Subtraction
  echo ($a * $b)."<br>";  // Multiplication
  echo ($a / $b)."<br>";  // Division
  echo (intdiv($a, $b))."<br>";   // Integer division
  echo ($a % $b)."<br>";  // Modulo
  echo ($a ** $b)."<br>"; // Exponentiation 
?>
