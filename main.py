import yaml

input_yaml = {}

with open("swagger.yaml", 'r') as stream:
    try:
        input_yaml = yaml.safe_load(stream)
    except yaml.YAMLError as exc:
        print(exc)

final_config = {}

def process_path(path : {}):
    for http_method in path:
        print("  " + http_method)

for name, path in input_yaml["paths"].items():
    print(name)
    process_path(path)