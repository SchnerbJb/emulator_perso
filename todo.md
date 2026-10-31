todo : manufacture code
todo : cgb code
TODO Checksum



# Ideas :

- Have unique functions parameters for all variations


# access register

setter getter ? 

    - set_register_cpu(emulator, code, value)
        concatenate if code point to 2 register
    - set_memory_register
        check for writability
    - get_memory_register
        check for readability of registers



# Instructions :

- see by opcode how to identify block kinda ?

    -> ld r8 r8: 0b01xxxyyy
    // block 2
    -> Arithmetique8bit : 0b10xxxyyy
    -> imm8 operation on A : 0b11000110 -> 0b11111110
    hard coder le reste

# carry problem

    -> implementer operation basique
        (+, -) qui set H Z et C automatiquement

# Timer :
    Ajouter un timer d'~4MiHz et tick a chaque operation 
        de + d'un machine cycle ?

    or

    Update function using tick() 
        

