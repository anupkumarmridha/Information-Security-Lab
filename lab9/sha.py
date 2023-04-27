import hashlib
def sha256(input):
    # Create a new SHA-256 hash object
    hash = hashlib.sha256()
    # Update the hash object with the input string
    hash.update(input.encode('utf-8'))
    # Get the hex digest of the hash value
    output = hash.hexdigest()
    return output
    # Test the function with a sample input
input = "Hello, world!"
output = sha256(input)
print("Hash Value:", output)
