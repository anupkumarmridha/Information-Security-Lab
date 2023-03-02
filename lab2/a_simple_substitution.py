import string

def simple_substitution_encrypt(message, key):
    """
    Encrypts a message using a simple substitution cipher.

    Args:
        message (str): The message to be encrypted.
        key (str): The substitution key, which should be a permutation of the characters used in the message.

    Returns:
        str: The encrypted message.
    """
    # Create a mapping between the characters used in the message and the key
    characters = string.ascii_letters + string.digits
    mapping = dict(zip(characters, key))

    # Encrypt the message
    encrypted = ''
    for char in message:
        if char in characters:
            encrypted += mapping[char]
        else:
            encrypted += char

    return encrypted

def simple_substitution_decrypt(encrypted, key):
    """
    Decrypts a message encrypted using a simple substitution cipher.

    Args:
        encrypted (str): The encrypted message to be decrypted.
        key (str): The substitution key that was used to encrypt the message.

    Returns:
        str: The decrypted message.
    """
    # Create a mapping between the key and the characters used in the message
    characters = string.ascii_letters + string.digits
    mapping = dict(zip(key, characters))

    # Decrypt the message
    decrypted = ''
    for char in encrypted:
        if char in key:
            decrypted += mapping[char]
        else:
            decrypted += char

    return decrypted

key = 'mnbvcxzlkjhgfdsapoiuytrewq0987654321'
message = input("Enter Your Message: ")
encrypted = simple_substitution_encrypt(message, key)
decrypted = simple_substitution_decrypt(encrypted, key)

print('Original message: ', message)
print('Encrypted message:', encrypted)
print('Decrypted message:', decrypted)
