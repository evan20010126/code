<?php // class.php
  $object = new User;
  print_r($object);
  class User
  {
    public $name = "default_name", $password = "default_pw";
    function save_user()
    {
      echo "Save User code goes here";
    }
  }
?>