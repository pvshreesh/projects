<?php
    session_start();
?>

<html>

<head>

	<title> details</title>

    <style type="text/css">

	#uid1 {
		border: 1.25px solid black;
		width:150px;
		color:black;
		padding:2px;
		position:absolute;
		top:350px;
		left:500px;
		color:green;
		font-size:20px;
		font-family:Arial;
			
	}
	#uname1 {
		border: 1.25px solid black;
		width:150px;
		color:black;
		padding:2px;
		position:absolute;
		top:380px;
		left:500px;
		color:green;
		font-size:20px;
		font-family:Arial;
			
	}
	#mno1 {
		border: 1.25px solid black;
		width:150px;
		color:black;
		padding:2px;
		position:absolute;
		top:410px;
		left:500px;
		color:green;
		font-size:20px;
		font-family:Arial;
			
	}
	#uid {
		border: 1.25px solid black;
		width:150px;
		color:black;
		padding:2px;
		position:absolute;
		top:350px;
		left:330px;
		color:blue;
		font-size:20px;
		font-family:Arial;
			
	}
	#uname {
		border: 1.25px solid black;
		width:150px;
		color:black;
		padding:2px;
		position:absolute;
		top:380px;
		left:330px;
		color:blue;
		font-size:20px;
		font-family:Arial;
			
	}
	#mno {
		border: 1.25px solid black;
		width:150px;
		color:black;
		padding:2px;
		position:absolute;
		top:410px;
		left:330px;
		color:blue;
		font-size:20px;
		font-family:Arial;
			
	}
	img {
		position:absolute;
		top:150px;
		left:400px;
		width:200px;
		height:200px;
	}
	#butn {
		position:absolute;
		top:100px;
		left:1700px;
		font-size:15px;
	}
	#butn2 {
		position:absolute;
		top:500px;
		left:350px;
	}
	
	</style>
    
</head>

<body> 
	<form method="post">
		<div id="butn"><button type="submit" value="logout" id="logout" name="logout" > Logout </button> </div>
		<div id="butn2"><button type="submit" value="back" id="back" name="back" > back </button> </div>
    </form>   
    

	<?php
		if(!isset($_SESSION['uid'])){
		    header('location:login.php');
	    }
		if(isset($_POST['logout'])){
            session_unset();
            session_destroy();
            header('location:login.php');

        }
		if(isset($_POST['back'])){
            header('location:home.php');
            
        }
		$uname=$_SESSION["uname"];
		$uid=$_SESSION["uid"];
		$mno=$_SESSION["mno"];
        
    ?>
	
	<div id="uid"> User ID</div>
	<div id="uname"> User Name</div>
	<div id="mno"> Mobile Number</div>
	
	<div id="uname1">
	<?php
        echo "$uname";
    ?>
	</div>
	<div id="uid1">
	<?php
        echo "$uid";
    ?>
	</div>
	<div id="mno1">
	<?php
        echo "$mno";
    ?>
	</div>
	
	<img src="2.png"/>
	

</body>
</html>

