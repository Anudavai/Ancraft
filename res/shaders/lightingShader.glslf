#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
  
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos;
uniform vec3 viewPos;

void main()
{
    // ambient
    float ambientStrength = 0.15;
    vec3 ambient = ambientStrength * lightColor;
  	
    // diffuse 
    vec3 n_normal = normalize(Normal);
    vec3 n_lightDir = normalize(lightPos - FragPos);
    float diffCoeff = max(dot(n_normal, n_lightDir), 0.0);
    vec3 diffuseColor = diffCoeff * lightColor;
    
    // specular
    float specularStrength = 0.5;
    vec3 n_viewDir = normalize(viewPos - FragPos);
    vec3 n_reflectDir = reflect(-n_lightDir, n_normal);  
    float specCoef = pow(max(dot(n_viewDir, n_reflectDir), 0.0), 32);
    vec3 specular = specularStrength * specCoef * lightColor;  
        
    vec3 resultColor = (ambient + diffuseColor + specular) * objectColor;
    FragColor = vec4(resultColor, 1.0);
}  
