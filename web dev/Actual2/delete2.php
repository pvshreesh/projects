<?php
$slno= filter_input(INPUT_POST, 'slno', FILTER_SANITIZE_NUMBER_INT);
$success = false;
if ($slno) {
    $conn = mysqli_connect("localhost","root","snores","login"); //connection to database 
    $funcao="DELETE FROM annex WHERE slno = " . $slno;
    $result=mysqli_query($conn, $funcao);
    $success = true;
}
header('Content-Type: application/json');
echo json_encode(array('success' => $success));
?>