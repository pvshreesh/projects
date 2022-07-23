<?php
    session_start();
?>


<html>

<head>

	<title> Update</title>

	<style type="text/css">
	#uname2 {
		position:absolute;
		top:325px;
		left:480px;
	}
	#uid2 {
		position:absolute;
		top:350px;
		left:480px;
	}
	#e {
		position:absolute;
		top:150px;
		left:150px;
		font-size:35px;
		color:red;
	}
			
    #butn {

		position:absolute;
		top:190px;
		left:350px;
		font-size:15px;
	}

	#uid1 {
		border: 1.25px solid black;
		width:125px;
		color:black;
		padding:2px;
		position:absolute;
		top:350px;
		left:330px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}
	#uname1 {
		border: 1.25px solid black;
		width:125px;
		color:black;
		padding:2px;
		position:absolute;
		top:325px;
		left:330px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}	

	#link {
		
		width:275px;
		
		position:absolute;
		top:450px;
		left:330px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}
	</style>

</head>

<body> 
	
	<form method="post">
	
		<h2>Personal info</h2>
		<div id="uname1"> Address</div>
		<input type="text" name="uname" id="uname2" placeholder="Address"> 
		<div id="uid1"> E-Mail</div>
		<input type="text" name="pw" id="uid2" placeholder="mail ID"> 
		<div id="butn"><button type="submit" value="submit" id="butn" name="submit" > Add/Update </button> </div>
	</form>

    
	<div id="link">
	<a href="login.php">Home</a> 
	</div>
	<?php
	if(!isset($_SESSION['uid'])){
		header('location:login.php');
	}
	
    if(isset($_POST['submit'])){
    	
		$servername='localhost';
     	$user='root';
    	$pwd='';
     	$db='user';
			
     	$conn = mysqli_connect($servername, $user, $pwd,$db);

		
     	if (!$conn) {
     		die("Connection failed: " . mysqli_connect_error());
     	}
     	
     	$uid=$_SESSION['uid'];
        $address=$_POST['uname'];
     	$mail=$_POST['pw'];
		date_default_timezone_set('Asia/Kolkata');
		$date = date('Y-m-d h:i:s', time());
		
		$query1="SELECT * from personal_data WHERE uid='$uid'";
		$query_run= mysqli_query($conn,$query1);
		$result=mysqli_fetch_assoc($query_run);
		$test=$result['uid'];

		if(strlen($address)<3 || strlen($mail)<3 ){
			echo "<div id='e'>enter valid inputs</div>";
		}
		
		else{	
			if($test){
				$query= "UPDATE personal_data set address='$address', mail='$mail',last_update='$date' where uid='$uid'";
				mysqli_query($conn,$query);
				echo "user edited";
				header('location:home.php');
			}
            else{
     		    $query="INSERT INTO personal_data (uid,address,mail,last_update) VALUES ('$uid','$address','$mail','$date')";
		
			    if(mysqli_query($conn,$query))
			    {
				    echo "User Added";
					header('location:home.php');
			    }
			    else
			    {
				    echo "Unable to Add User. Try again later.";
			    }
            }
		}
 	}
    ?>
	
</body>
</html>