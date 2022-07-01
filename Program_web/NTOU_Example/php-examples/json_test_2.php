<?php // json_test_2.php
  $ary = array(
    array(
        'Name' => '涼宮ハルヒン',
        'Book' => '涼宮ハルヒの憂鬱',
        'Attrib' => 'SOS団長'
    ),
    array(
        'Name' => 'キョン',
        'Book' => '涼宮ハルヒの憂鬱',
        'Attrib' => '普通人'
    ),
    array(
        'Name' => '長門有希',
        'Book' => '涼宮ハルヒの憂鬱',
        'Attrib' => '宇宙人'
    ),
    array(
        'Name' => '朝比奈みくる',
        'Book' => '涼宮ハルヒの憂鬱',
        'Attrib' => '穿越時空的少女'
    ),
    array(
        'Name' => '古泉一樹',
        'Book' => '涼宮ハルヒの憂鬱',
        'Attrib' => '超能力戰隊少年'
    )
  );
 
  $serialized_ar = json_encode($ary,  JSON_UNESCAPED_UNICODE + JSON_PRETTY_PRINT);
 
  $ary2 = json_decode($serialized_ar);
  
  header("Content-Type:application/json; charset=utf-8");
  echo urldecode($serialized_ar);
?>