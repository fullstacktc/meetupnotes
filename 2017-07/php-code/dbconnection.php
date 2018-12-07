<?php

try {
	$db_handle = new PDO('mysql:host=mariadb;dbname=confluent', 'confluent', 'confluent');
    print 'Connection successful';
} catch (PDOException $e) {
	print "Error: " . $e->getMessage() . "<br>";
	die();
}
