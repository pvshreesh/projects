<?php
$server="localhost";
$nm="root";
$pwd="snores";
$db="login";
$con=mysqli_connect($server,$nm,$pwd,$db);

$field = $_POST['field'];
$value = $_POST['value'];
$editid = $_POST['id'];

$query = "UPDATE annex SET ".$field."='".$value."' WHERE slno=".$editid;
mysqli_query($con,$query);

echo 1;
?>