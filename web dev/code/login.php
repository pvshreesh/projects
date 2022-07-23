<?php
	session_start();
?>

<html>

<head>

	<title> login</title>

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
		color:blue;
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
		color:blue;
		font-size:20px;
		font-family:Arial;
			
	}		

	#link {
		
		width:275px;
		
		position:absolute;
		top:450px;
		left:330px;
		color:blue;
		font-size:15px;
		font-family:Arial;
			
	}

	#link2 {
		
		width:275px;
		
		position:absolute;
		top:450px;
		left:530px;
		color:blue;
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
	#p {
		
		width:275px;
		
		position:absolute;
		top:150px;
		left:130px;
		color:red;
		font-size:25px;
		font-family:Arial;
			
	}
	</style>

</head>

<body> 
	
	<form method="post">
	
		<h2>LOGIN</h2>
		<div id="uid1"> User ID</div>
		<input type="text" name="uid" id="uid2" placeholder="User ID"> <br>
		<div id="pw1"> Password</div>
		<input type="Password" name="pw" id="pw2" placeholder="Password"> <br>
		<div id="butn"><button type="submit" value="submit" id="butn" name="submit" > Login </button> </div>
	</form>
	<div id="link">
	<a href="register.php">New User</a> 
	</div>
	<div id="link2">
	<a href="fp.php">Forgot Password</a>
	</div>
	<img src="1.png"/>
	<div id="p">


	<?php
	if(isset($_SESSION['uid'])){
		header('location:home.php');
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
		$uid=$_POST['uid'];
		$pw=$_POST['pw'];
		if (strlen($uid)<3){
			if (strlen($pw)<3){
				echo "enter valid ID and Password";
			}
			else{
				echo "enter valid user ID";
			}
		}
		elseif (strlen($pw)<3){
			echo "enter valid Password";
		}
		else{
			$query="SELECT password from users where userid='$uid'";
			$query_run= mysqli_query($conn,$query);
			
			$result=mysqli_fetch_assoc($query_run);
			$resultstring=$result['password'];

			$query="SELECT * from users where userid='$uid'";
    		$query_run= mysqli_query($conn,$query);
			$result=mysqli_fetch_assoc($query_run);
			$uname=$result['username'];
			$mno=$result['mno'];

			if($pw==$resultstring)
			{
		   		$_SESSION['uid']=$uid;
		   		$_SESSION['pw']=$pw;
				$_SESSION['uname']=$uname;
				$_SESSION['mno']=$mno;
				header('location:home.php');
			}
			else
			{
		    	echo "Invalid Credentials!";
			}
		}
	}

    ?>
	</div>

	



</body>
</html>