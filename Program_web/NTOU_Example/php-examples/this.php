<?php // this.php
  $new_user = new User;
  $new_user->password = "new password";
  echo $new_user->get_password();
  class User
  {
    public $name, $password;

    function get_password()
    {
      return $this->password;
    }
  }
?>
