for myfile in *.png; 
	do 
		echo Converting $myfile...;
		gimp -i -b "(CardPerspective \"$myfile\")" -b "(gimp-quit 0)";
	done;

