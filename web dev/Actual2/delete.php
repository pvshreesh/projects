<?php
$hpvpenqno= filter_input(INPUT_POST, 'hpvpenqno', FILTER_SANITIZE_NUMBER_INT);
$success = false;
if ($hpvpenqno) {
    $conn = mysqli_connect("localhost","root","snores","login"); //connection to database 
    $funcao="DELETE FROM upload WHERE hpvpenqno = " . $hpvpenqno;
    $result=mysqli_query($conn, $funcao);
    $success = true;
}
header('Content-Type: application/json');
echo json_encode(array('success' => $success));
?>