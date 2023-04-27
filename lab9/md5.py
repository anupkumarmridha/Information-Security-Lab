import hashlib

def md5(input):
    # Create a new MD5 hash object
    hash = hashlib.md5()
    # Update the hash object with the input string
    hash.update(input.encode('utf-8'))
    # Get the hex digest of the hash value
    output = hash.hexdigest()
    return output
# Test the function with a sample input
input = "Hello, world!"
output = md5(input)
print("Hash Value:", output)
