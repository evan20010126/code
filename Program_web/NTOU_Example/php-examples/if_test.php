<?php //if_test.php
  $bank_balance = 300;
  $savings = 0;
  if ($bank_balance < 100)
  {
    $money = 1000;
    $bank_balance += $money;
  }
  elseif ($bank_balance > 200)
  {
    $savings += 100;
    $bank_balance -= 100;
  }
  else
  {
    $savings += 50;
    $bank_balance -= 50;
  }
  echo "Balance: ".$bank_balance.", saveings: ".$savings;
?>
