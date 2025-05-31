# set auto-load safe-path .

# A dummy command to prove that anything is working
define du
  p/x 15
end

# A command to toggle asm mode


define led
  # RCC AHB1 peripheral clock enable register (RCC_AHB1ENR)
  p/x *0x40023830
end
