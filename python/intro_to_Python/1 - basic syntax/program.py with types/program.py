def greet(name: str) -> None:  # "type hints" added!
    print(f"Hello, {name}!")  # hover over `name` to see it knows it's a str!


if __name__ == "__main__":
    greet("Amiel")
