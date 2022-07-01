<?php // sql_test.php
  require_once 'login.php';
  $conn = new mysqli($hn, $un, $pw, $db);
  if ($conn->connect_error) die("Fatal Error");

  $keyword = "";

  // delete a record
  if (isset($_POST['delete']) && isset($_POST['isbn']))
  {
    $isbn   = get_post($conn, 'isbn');
    $query  = "DELETE FROM classics WHERE isbn='$isbn'";
    $result = $conn->query($query);
    if (!$result) echo "DELETE failed<br><br>";
    echo "<script>alert('".$isbn." is deleted!')</script>";
  }

  // search records
  if (isset($_POST['search']) && isset($_POST['keyword']))
  {
    $keyword = get_post($conn, 'keyword');
  }

  // insert a record
  if (isset($_POST['author'])   &&
      isset($_POST['title'])    &&
      isset($_POST['category']) &&
      isset($_POST['year'])     &&
      isset($_POST['isbn']))
  {
    $author   = get_post($conn, 'author');
    $title    = get_post($conn, 'title');
    $category = get_post($conn, 'category');
    $year     = get_post($conn, 'year');
    $isbn     = get_post($conn, 'isbn');
    $query    = "INSERT INTO classics VALUES" .
      "('$author', '$title', '$category', '$year', '$isbn')";
    $result   = $conn->query($query);
    if (!$result) echo "INSERT failed<br><br>";
  }

  // show the search form
  echo <<<_END
  <form action="sql_test_2.php" method="post"><pre>
    Title Keyword <input type="search" name="keyword">
    <input type='hidden' name='search' value='yes'>
    <br><input type="submit" value="SEARCH">
    </pre></form>
_END;

  // show the insert form
  echo <<<_END
    <form action="sql_test_2.php" method="post"><pre>
      Author <input type="text" name="author">
       Title <input type="text" name="title">
    Category <input type="text" name="category">
        Year <input type="text" name="year">
        ISBN <input type="text" name="isbn">
  <br><input type="submit" value="ADD RECORD">
    </pre></form>
_END;

  // show all records
  $query  = "SELECT * FROM classics where title LIKE '%$keyword%'";

  $result = $conn->query($query);
  if (!$result) die ("Database access failed or nothing can be fetched!");

  $rows = $result->num_rows;

  for ($j = 0 ; $j < $rows ; ++$j)
  {
    $row = $result->fetch_assoc();

    $r0 = htmlspecialchars($row['author']);
    $r1 = htmlspecialchars($row['title']);
    $r2 = htmlspecialchars($row['category']);
    $r3 = htmlspecialchars($row['year']);
    $r4 = htmlspecialchars($row['isbn']);
    
    echo <<<_END
      <pre style='margin-bottom:0px;'>
        Author $r0
         Title $r1
      Category $r2
          Year $r3
          ISBN $r4
      </pre>
      <form style='margin-top:0px;' action='sql_test_2.php' method='post'>
      <input type='hidden' name='delete' value='yes'>
      <input type='hidden' name='isbn' value='$r4'>
      <input type='submit' value='DELETE RECORD'></form>
      <br>
_END;
  }

  // close db connection
  $result->close();
  $conn->close();

  function get_post($conn, $var)
  {
    return $conn->real_escape_string($_POST[$var]);
  }

?>