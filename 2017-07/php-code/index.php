<?php

print 'Welcome to Confluent Space';

if(isset($_GET['name'])) {
    print ', ' . $_GET['name'];
}
