<?php
  $page = "Other";
  switch ($page)
  {
    case "Home":
      echo "You selected Home";
      break;
    case "About":
      echo "You selected About";
      break;
    case "News":
      echo "You selected News";
      break;
    default:
      echo "You are unauthorized!";
      break;
  }  
?>
