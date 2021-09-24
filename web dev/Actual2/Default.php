<?php

$conn = mysqli_connect("localhost","root","snores","login");


$sql = "SELECT * FROM upload";
$result = mysqli_query($conn, $sql);
$files = mysqli_fetch_all($result,MYSQLI_ASSOC);
if(isset($_GET['file_id']))
{
    $id = $_GET['file_id'];
    $sql3 = "SELECT * FROM upload WHERE id='$id'";
    $result = mysqli_query($conn, $sql3);
    $file3 = mysqli_fetch_assoc($result);
    $filepath = 'uploads/'.$file3['id'];
    
        if(file_exists($filepath))
    {
        
             	header('Content-Type: application/octet-stream');
     		header('Content-description: File Transfer');
     		header('Content-disposition: attachment; filename='.basename($filepath));
     		header('Expires:0');
     		header('Cache-Control: must-revalidate');
     		header('Pragma: public');
     		header('Content-Length:'.filesize('uploads/'.$file3['id']));
     		readfile('uploads'.$file3['id']);

    }

}  

?>





<!DOCTYPE html>
<html>
<head>
	<title>Default Page</title>
	<link href="Top.css" rel="stylesheet" type="text/css"  />
	<link href="Default.css" rel="stylesheet" type="text/css"  />
</head>
<body>
	<header class="headers">
	<div >
	<img src="icon1.jpg" class="icon1" alt="Icon 1" />
	<img src="icon2.jpeg" class="icon2" alt="Icon 2" />
	<h1 class="head1">POWER SECTOR-MARKETING</h1>
	<br>
	<form action="Log.php">
	<button class="button2" name="login"><span> ADMIN LOGIN</span></button>
	</form>
	<br><br>
        <div id="top_buttons">
	<button class="button1">HOME</button>
	<button class="button1">ABOUT US</button>
	<button class="button1">OUR CUSTOMERS</button>
	<button class="button1">BUSINESS ENVIRONMENT</button>
	<button class="button1">ONLINE SYSTEM</button>
	<button class="button1">TENDERS</button>
	<button class="button1">CONTRACTS</button>
	<button class="button1">EMPLOYEE CORNER</button>
        </div>


</div>
</header>
<main>
	<div >
		<table>
			<tr class="ct">
				<th >Current Tenders</th>
			</tr>
		</table>
	
	
		<table>
			<tr class="at">
				<th></th>
				<th>All Tenders</th>
				<th></th>
			</tr>
		</table>
	
		<table >
			<thead class="tr1 tr1b">
				 <th>Marketing Group</th>
            <th>HPVPENQ.NO</th>
            <th>Consultant/Customer name</th>
            <th>Consultant/CustomerEnq</th>
            <th>DueDate</th>
            <th>PhNo</th>
            <th>Description</th>
            <th>HPVP OfferRef</th>
            <th>Delivery</th>
            <th>Remarks</th>
            <th>Actions</th>            
            </thead>
        <tbody class="tr1">           
            <?php foreach($files as $file): ?>
            <tr>
                
                <td><?php echo $file['marketinggroup'];?></td>
                <td><?php echo $file['hpvpenqno'];?></td>
                <td><?php echo $file['consultantname'];?></td>
                <td><?php echo $file['consultantenqno'];?></td>
                <td><?php echo $file['duedate'];?></td>
                <td><?php echo $file['phno'];?></td>
                <td><?php echo $file['description'];?></td>
                <td><?php echo $file['hpvpofferref'];?></td>
                <td><?php echo $file['delivery'];?></td>
                <td><?php echo $file['remarks'];?></td>               
                <td>
                    <a class="a1" href="Default.php?file_id=<?php echo $file['id'];?>">Download</a>                   
                </td>
            </tr>           
            <?php endforeach ; ?>
            
        </tbody>
       </table>
	</div>
</main>
</body>
</html>


