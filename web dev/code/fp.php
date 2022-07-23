<html>

<head>

	<title> Forgot Password</title>

	<style type="text/css">

				
	input[type=text]{

		position:absolute;
		top:350px;
		left:480px;
		font-size:20px;
	}
	input[type=password]{

		position:absolute;
		top:400px;
		left:480px;
		font-size:20px;
	}
			
    #butn {

		position:absolute;
		top:190px;
		left:375px;
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
		font-size:20px;
		font-family:Arial;
			
	}

	#pw1 {
		border: 1.25px solid black;
		width:125px;
		color:black;
		padding:2px;
		position:absolute;
		top:400px;
		left:330px;
		color:red;
		font-size:20px;
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

	#link2 {
		
		width:275px;
		
		position:absolute;
		top:450px;
		left:530px;
		color:red;
		font-size:15px;
		font-family:Arial;
			
	}

	img {
		position:absolute;
		top:200px;
		left:888px;
		width:600px;
		height:400px;
	}
	</style>

</head>

<body> 
	
	<form method="post">
	
		<h2>Forgot Password</h2>
		<div id="uid1"> User ID</div>
		<input type="text" name="uid" id="uid2" placeholder="User ID"> <br>
		<div id="pw1"> Password</div>
		<input type="Password" name="pw" id="pw2" placeholder="Password"> <br>
		<div id="butn"><button type="submit" value="submit" id="butn" name="submit" > Login </button> </div>
	</form>

    <div id="link">
	<a href="login.php">Home</a> 
	</div>

	<?php
    if(isset($_POST['submit'])){
    	
		$servername='localhost';
     	$user='root';
    	$pwd='';
     	$db='user';
			
     	$conn = mysqli_connect($servername, $user, $pwd,$db);

     
     	if (!$conn) {
     		die("Connection failed: " . mysqli_connect_error());
     	}
     	$pw=$_POST['pw'];
     	$uid=$_POST['uid'];

		if (strlen($uid)<3){
			echo "enter valid user ID";
		}
		elseif (strlen($pw)<3){
			echo "enter valid Password";
		}
		else{
     		$query= "UPDATE users set password='$pw' where userid='$uid'";
			$query2="SELECT password from users where userid='$uid'";
			$result=mysqli_query($conn,$query2);
			if(mysqli_num_rows($result) > 0)
			{
				mysqli_query($conn,$query);
				echo "User edited";
			}
			else
			{
				echo "Unable to edit User or user doesnot exist. Try again later.";
			}
		}
 	}
    ?>
	
</body>
</html>