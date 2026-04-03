#!/bin/bash

##########################
# TESTING WITH ONLY ZEROS AND ONES
##########################
echo "testing ./philo 0 0 0 0"
if timeout 0.1s ./philo 0 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 0 1"
if timeout 0.1s ./philo 0 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 1 0"
if timeout 0.1s ./philo 0 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 1 1"
if timeout 0.1s ./philo 0 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 0 0"
if timeout 0.1s ./philo 0 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 0 1"
if timeout 0.1s ./philo 0 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 1 0"
if timeout 0.1s ./philo 0 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 1 1"
if timeout 0.1s ./philo 0 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 0 0"
if timeout 0.1s ./philo 1 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 0 1"
if timeout 0.1s ./philo 1 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 1 0"
if timeout 0.1s ./philo 1 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 1 1"
if timeout 0.1s ./philo 1 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 0 0"
if timeout 0.1s ./philo 1 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 0 1"
if timeout 0.1s ./philo 1 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


echo "testing ./philo 1 1 1 0"
if timeout 0.1s ./philo 1 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 1 1 1 1"
if timeout 0.1s ./philo 1 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi


# ##########################
# # TESTING WITH WORKING NUMBER OF PHILO
# ##########################
echo "testing ./philo 2 0 0 0"
if timeout 0.1s ./philo 2 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 0 0 1"
if timeout 0.1s ./philo 2 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 0 1 0"
if timeout 0.1s ./philo 2 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 0 1 1"
if timeout 0.1s ./philo 2 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 1 0 0"
if timeout 0.1s ./philo 2 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 1 0 1"
if timeout 0.1s ./philo 2 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 1 1 0"
if timeout 0.1s ./philo 2 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 1 1 1"
if timeout 0.1s ./philo 2 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi


# ##########################
# # TESTING WITH '-' VALUES
# ##########################
echo "testing ./philo -2 410 200 200"
if timeout 0.1s ./philo -2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 -410 200 200"
if timeout 0.1s ./philo 2 -410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 -200 200"
if timeout 0.1s ./philo 2 410 -200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 -200"
if timeout 0.1s ./philo 2 410 200 -200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

# ##########################
# # TESTING WITH '+-' VALUES
# ##########################
echo "testing ./philo +-2 410 200 200"
if timeout 0.1s ./philo +-2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 +-410 200 200"
if timeout 0.1s ./philo 2 +-410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 +-200 200"
if timeout 0.1s ./philo 2 410 +-200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 +-200"
if timeout 0.1s ./philo 2 410 200 +-200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo -+2 410 200 200"
if timeout 0.1s ./philo -+2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 -+410 200 200"
if timeout 0.1s ./philo 2 -+410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 -+200 200"
if timeout 0.1s ./philo 2 410 -+200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 -+200"
if timeout 0.1s ./philo 2 410 200 -+200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


# ##########################
# # TESTING WITH '+-' + ZEROS VALUES
# ##########################
echo "testing ./philo -000+002 +00410 0+200 0-200"
if timeout 0.1s ./philo -000+002 +00410 0+200 0-200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 00+2 0-0410 200 200"
if timeout 0.1s ./philo 00+2 0-0410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo +0-2 -0+410 +0-200 -0+200"
if timeout 0.1s ./philo +0-2 -0+410 +0-200 -0+200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0+02 0410 -0200 +0200"
if timeout 0.1s ./philo 0+02 0410 -0200 +0200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 +410 00-200 0+200"
if timeout 0.1s ./philo 2 +410 00-200 0+200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo -+2 +-410 +00200 -00200"
if timeout 0.1s ./philo -+2 +-410 +00200 -00200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo +02 0+0410 +0-200 -0+200"
if timeout 0.1s ./philo +02 0+0410 +0-200 -0+200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 00+2 -00410 +0200 -0200"
if timeout 0.1s ./philo 00+2 -00410 +0200 -0200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


echo "testing ./philo a2 410 200 200"
if timeout 0.1s ./philo a2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2a 410 200 200"
if timeout 0.1s ./philo 2a 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 a410 200 200"
if timeout 0.1s ./philo 2 a410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410a 200 200"
if timeout 0.1s ./philo 2 410a 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 a200 200"
if timeout 0.1s ./philo 2 410 a200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200a 200"
if timeout 0.1s ./philo 2 410 200a 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 a200"
if timeout 0.1s ./philo 2 410 200 a200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200a"
if timeout 0.1s ./philo 2 410 200 200a 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


# ##########################
# # TESTING WITH ZEROS
# ##########################
echo "testing ./philo 000002 410 200 200"
if timeout 0.1s ./philo 000002 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 00000410 200 200"
if timeout 0.1s ./philo 2 00000410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 000000200 200"
if timeout 0.1s ./philo 2 410 000000200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 200 00000000000200"
if timeout 0.1s ./philo 2 410 200 00000000000200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 02 00410 200 200"
if timeout 0.1s ./philo 02 00410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 02 00410 00200 000200"
if timeout 0.1s ./philo 02 00410 00200 000200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 000002 0410 200 00000200"
if timeout 0.1s ./philo 000002 0410 200 00000200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 0000410 200 00000200"
if timeout 0.1s ./philo 2 0000410 200 00000200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi


# ##########################
# # TESTING WITH '+' VALUES
# ##########################
echo "testing ./philo +2 410 200 200"
if timeout 0.1s ./philo +2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 +410 200 200"
if timeout 0.1s ./philo 2 +410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 +200 200"
if timeout 0.1s ./philo 2 410 +200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 200 +200"
if timeout 0.1s ./philo 2 410 200 +200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

# ##########################
# # TESTING WITH 2'+' VALUES
# ##########################
echo "testing ./philo ++2 410 200 200"
if timeout 0.1s ./philo ++2 410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 ++410 200 200"
if timeout 0.1s ./philo 2 ++410 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 410 ++200 200"
if timeout 0.1s ./philo 2 410 ++200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 2 410 200 ++200"
if timeout 0.1s ./philo 2 410 200 ++200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;32mko\033[0m"
fi

# ##########################
# # TESTING QUANTITY OF ARGUMENTS
# ##########################
echo "testing ./philo"
if timeout 0.1s ./philo 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"   # should print ok because it is invalid
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2"
if timeout 0.1s ./philo 2 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"   # invalid → ok
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410"
if timeout 0.1s ./philo 2 410 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"   # invalid → ok
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200"
if timeout 0.1s ./philo 2 410 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"   # invalid → ok
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 200"
if timeout 0.1s ./philo 2 410 200 200 200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"   # valid → ko if invalid found
else
    echo -e "\033[1;32mok\033[0m"   # valid → ok
fi


# ##########################
# #TESTING WITH MAXIUM TIMES TO EAT ONLY ZERO
# ##########################
echo "testing ./philo 0 0 0 0 0"
if timeout 0.1s ./philo 0 0 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"   # invalid → ok
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 0 0 1"
if timeout 0.1s ./philo 0 0 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 0 1 0"
if timeout 0.1s ./philo 0 0 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 0 1 1"
if timeout 0.1s ./philo 0 0 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 1 0 0"
if timeout 0.1s ./philo 0 0 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 1 0 1"
if timeout 0.1s ./philo 0 0 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 1 1 0"
if timeout 0.1s ./philo 0 0 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 0 1 1 1"
if timeout 0.1s ./philo 0 0 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 0 0 0"
if timeout 0.1s ./philo 0 1 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 0 0 1"
if timeout 0.1s ./philo 0 1 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 0 1 0"
if timeout 0.1s ./philo 0 1 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 0 1 1"
if timeout 0.1s ./philo 0 1 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 1 0 0"
if timeout 0.1s ./philo 0 1 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 1 0 1"
if timeout 0.1s ./philo 0 1 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 1 1 0"
if timeout 0.1s ./philo 0 1 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0 1 1 1 1"
if timeout 0.1s ./philo 0 1 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 0 0 0"
if timeout 0.1s ./philo 1 0 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 0 0 1"
if timeout 0.1s ./philo 1 0 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 0 1 0"
if timeout 0.1s ./philo 1 0 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 0 1 1"
if timeout 0.1s ./philo 1 0 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 1 0 0"
if timeout 0.1s ./philo 1 0 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 1 0 1"
if timeout 0.1s ./philo 1 0 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 1 1 0"
if timeout 0.1s ./philo 1 0 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 0 1 1 1"
if timeout 0.1s ./philo 1 0 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"   # valid → ok
else
    echo -e "\033[1;32mko\033[0m"
fi

echo "testing ./philo 1 1 0 0 0"
if timeout 0.1s ./philo 1 1 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 0 0 1"
if timeout 0.1s ./philo 1 1 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 0 1 0"
if timeout 0.1s ./philo 1 1 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 0 1 1"
if timeout 0.1s ./philo 1 1 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 1 0 0"
if timeout 0.1s ./philo 1 1 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 1 0 1"
if timeout 0.1s ./philo 1 1 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 1 1 1 1 0"
if timeout 0.1s ./philo 1 1 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"   # valid → ok
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 1 1 1 1 1"
if timeout 0.1s ./philo 1 1 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"   # valid → ok
else
    echo -e "\033[1;32mok\033[0m"
fi


# ##########################
# #TESTING WITH MAXIUM TIMES TO EAT VALID PHILO NUMBER
# ##########################

echo "testing ./philo 2 0 0 0 0"
if timeout 0.1s ./philo 2 0 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 0 0 0 1"
if timeout 0.1s ./philo 2 0 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 0 0 1 0"
if timeout 0.1s ./philo 2 0 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 0 0 1 1"
if timeout 0.1s ./philo 2 0 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 0 1 0 0"
if timeout 0.1s ./philo 2 0 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 0 1 0 1"
if timeout 0.1s ./philo 2 0 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 0 1 1 0"
if timeout 0.1s ./philo 2 0 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 0 1 1 1"
if timeout 0.1s ./philo 2 0 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 1 0 0 0"
if timeout 0.1s ./philo 2 1 0 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 1 0 0 1"
if timeout 0.1s ./philo 2 1 0 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 1 0 1 0"
if timeout 0.1s ./philo 2 1 0 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 1 0 1 1"
if timeout 0.1s ./philo 2 1 0 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 1 1 0 0"
if timeout 0.1s ./philo 2 1 1 0 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 1 1 0 1"
if timeout 0.1s ./philo 2 1 1 0 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 1 1 1 0"
if timeout 0.1s ./philo 2 1 1 1 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 1 1 1 1"
if timeout 0.1s ./philo 2 1 1 1 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"   # valid → ok
else
    echo -e "\033[1;32mok\033[0m"
fi


# ##########################
# #TESTING WITH MAXIUM TIMES TO EAT + LETTERS
# ##########################
echo "testing ./philo a2 410 200 200 1"
if timeout 0.1s ./philo a2 410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2a 410 200 200 1"
if timeout 0.1s ./philo 2a 410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 a410 200 200 1"
if timeout 0.1s ./philo 2 a410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410a 200 200 1"
if timeout 0.1s ./philo 2 410a 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 a200 200 1"
if timeout 0.1s ./philo 2 410 a200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200a 200 1"
if timeout 0.1s ./philo 2 410 200a 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 a200 1"
if timeout 0.1s ./philo 2 410 200 a200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200a 1"
if timeout 0.1s ./philo 2 410 200 200a 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 a1"
if timeout 0.1s ./philo 2 410 200 200 a1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 1a"
if timeout 0.1s ./philo 2 410 200 200 1a 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi



# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + ZEROS
# ##########################################
echo "testing ./philo 000002 410 200 200 1"
if timeout 0.1s ./philo 000002 410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 00000410 200 200 1"
if timeout 0.1s ./philo 2 00000410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 000000200 200 1"
if timeout 0.1s ./philo 2 410 000000200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 200 000000200 1"
if timeout 0.1s ./philo 2 410 200 000000200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 02 00410 200 200 1"
if timeout 0.1s ./philo 02 00410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 02 00410 00200 000200 1"
if timeout 0.1s ./philo 02 00410 00200 000200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 000002 0410 200 00000200 1"
if timeout 0.1s ./philo 000002 0410 200 00000200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 0000410 200 00000200 1"
if timeout 0.1s ./philo 2 0000410 200 00000200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 200 200 000000200"
if timeout 0.1s ./philo 2 410 200 200 000000200 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi


# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + PLUS
# ##########################################
echo "testing ./philo +2 410 200 200 1"
if timeout 0.1s ./philo +2 410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 +410 200 200 1"
if timeout 0.1s ./philo 2 +410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 +200 200 1"
if timeout 0.1s ./philo 2 410 +200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 200 +200 1"
if timeout 0.1s ./philo 2 410 200 +200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 200 200 +1"
if timeout 0.1s ./philo 2 410 200 200 +1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi


# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + MINUS
# ##########################################
echo "testing ./philo -2 410 200 200 1"
if timeout 0.1s ./philo -2 410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 -410 200 200 1"
if timeout 0.1s ./philo 2 -410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 -200 200 1"
if timeout 0.1s ./philo 2 410 -200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 -200 1"
if timeout 0.1s ./philo 2 410 200 -200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 -1"
if timeout 0.1s ./philo 2 410 200 200 -1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"   # valid → ok
else
    echo -e "\033[1;32mko\033[0m"
fi


# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + MINUS AND PLUS
# ##########################################
echo "testing ./philo +-2 410 200 200 1"
if timeout 0.1s ./philo +-2 410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 +-410 200 200 1"
if timeout 0.1s ./philo 2 +-410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 +-200 200 1"
if timeout 0.1s ./philo 2 410 +-200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 +-200 1"
if timeout 0.1s ./philo 2 410 200 +-200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo -+2 410 200 200 1"
if timeout 0.1s ./philo -+2 410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 -+410 200 200 1"
if timeout 0.1s ./philo 2 -+410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 -+200 200 1"
if timeout 0.1s ./philo 2 410 -+200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 -+200 1"
if timeout 0.1s ./philo 2 410 200 -+200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 +-1"
if timeout 0.1s ./philo 2 410 200 200 +-1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + CRAZY
# ##########################################
echo "testing ./philo -000+002 +00410 0+200 0-200 1"
if timeout 0.1s ./philo -000+002 +00410 0+200 0-200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 00+2 0-0410 200 200 1"
if timeout 0.1s ./philo 00+2 0-0410 200 200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo +0-2 -0+410 +0-200 -0+200 1"
if timeout 0.1s ./philo +0-2 -0+410 +0-200 -0+200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0+02 0410 -0200 +0200 1"
if timeout 0.1s ./philo 0+02 0410 -0200 +0200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 +410 00-200 0+200 1"
if timeout 0.1s ./philo 2 +410 00-200 0+200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo -+2 +-410 +00200 -00200 1"
if timeout 0.1s ./philo -+2 +-410 +00200 -00200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo +02 0+0410 +0-200 -0+200 1"
if timeout 0.1s ./philo +02 0+0410 +0-200 -0+200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 00+2 -00410 +0200 -0200 1"
if timeout 0.1s ./philo 00+2 -00410 +0200 -0200 1 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo -000+002 +00410 0+200 0-200 0"
if timeout 0.1s ./philo -000+002 +00410 0+200 0-200 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 00+2 0-0410 200 200 0"
if timeout 0.1s ./philo 00+2 0-0410 200 200 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo +0-2 -0+410 +0-200 -0+200 0"
if timeout 0.1s ./philo +0-2 -0+410 +0-200 -0+200 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 0+02 0410 -0200 +0200 0"
if timeout 0.1s ./philo 0+02 0410 -0200 +0200 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 +410 00-200 0+200 0"
if timeout 0.1s ./philo 2 +410 00-200 0+200 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo -+2 +-410 +00200 -00200 0"
if timeout 0.1s ./philo -+2 +-410 +00200 -00200 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo +02 0+0410 +0-200 -0+200 0"
if timeout 0.1s ./philo +02 0+0410 +0-200 -0+200 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 00+2 -00410 +0200 -0200 0"
if timeout 0.1s ./philo 00+2 -00410 +0200 -0200 0 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi


# #########################################
# #TESTING WITH MAXIUM TIMES TO EAT + WEIRD
# ##########################################
echo "testing ./philo 2 410 200 200 a"
if timeout 0.1s ./philo 2 410 200 200 a 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 +"
if timeout 0.1s ./philo 2 410 200 200 + 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"
else
    echo -e "\033[1;32mok\033[0m"
fi


echo "testing ./philo 2 410 200 200 -"
if timeout 0.1s ./philo 2 410 200 200 - 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 +-"
if timeout 0.1s ./philo 2 410 200 200 +- 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 000001"
if timeout 0.1s ./philo 2 410 200 200 000001 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"   # valid → ok
else
    echo -e "\033[1;32mok\033[0m"
fi

echo "testing ./philo 2 410 200 200 -000001"
if timeout 0.1s ./philo 2 410 200 200 -000001 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;32mok\033[0m"
else
    echo -e "\033[1;31mko\033[0m"
fi

echo "testing ./philo 2 410 200 200 +000001"
if timeout 0.1s ./philo 2 410 200 200 +000001 2>&1 | grep -q "Invalid arguments"; then
    echo -e "\033[1;31mko\033[0m"   # valid → ok
else
    echo -e "\033[1;32mok\033[0m"
fi
