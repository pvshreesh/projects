<?php
    session_start();
?>

<html>

<head>

	<title> home</title>
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">

    <style type="text/css">
    #w {
		position:absolute;
		top:200px;
		left:700px;
        font-size:40px;
	}
    #butn {
		position:absolute;
		top:100px;
		left:1700px;
        font-size:15px;
	}
    #butn1 {
		position:absolute;
		top:300px;
		left:800px;
	}
    #butn2 {
		position:absolute;
		top:350px;
		left:800px;
	}
	#butn3 {
		position:absolute;
		top:400px;
		left:800px;
	}
	img {
		position:absolute;
		top:500px;
		left:575px;
		width:600px;
		height:350px;
	}	
	
	</style>
</head>

<body> 
    <form method="post">
        <div id="butn1"><button type="submit" value="profile" id="profile" name="profile"><i class="glyphicon glyphicon-user" style="font-size:36px;"></i>Profile</button></div>
        <div id="butn2"><button type="submit" value="update" id="update" name="update"><i class="glyphicon glyphicon-user" style="font-size:36px;"></i>update</button></div>
        <div id="butn3"><button type="submit" value="view" id="view" name="view"><i class="glyphicon glyphicon-user" style="font-size:36px;"></i>view</button></div>

        <div id="butn"><button type="submit" value="logout" id="logout" name="logout" > Logout </button> </div>
    </form>   
    <div id="w">Welcome <?php echo $_SESSION["uname"]; ?></div>
    <img src="3.png"/>

	<?php
        if(!isset($_SESSION['uid'])){
		    header('location:login.php');
	    }
        
        
        $uname=$_SESSION["uname"];
        
        if(isset($_POST['profile'])){
            header('location:details.php');
            
        }
        if(isset($_POST['update'])){
            header('location:update.php');
            
        }
        if(isset($_POST['view'])){
            header('location:view.php');
            
        }

        if(isset($_POST['logout'])){
            session_unset();
            session_destroy();
            header('location:login.php');

        }
    ?>
	

</body>
</html>





